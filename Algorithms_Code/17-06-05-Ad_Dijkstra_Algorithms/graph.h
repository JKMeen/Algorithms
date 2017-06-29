#include <iostream>
#include <iomanip>
using namespace std;
enum { ö�� = 0, ����, ����, ��ȣ, ���, �¿� };
class AdjacentMatrix
{
private:
	int vertexMaxNumber;
	int **adMatix;
	int numVertex;
	int *visit;
	int *dist;		// �Ÿ�
	bool *found;	// ã��
	int **path;		// �߰� ����
	int *numPath;	// �߰� ���� ����

public:
	AdjacentMatrix(int num = 100);
	~AdjacentMatrix();
	void insertVertex(int v);
	void insertEdge(int u, int v, int w);
	void insertEdge(int u, int v);
	bool isAdjacent(int v, int u);
	int  numDegree(int v);
	void DFS();			// ���� �켱 Ž�� ����
	void aDFS(int s);	// ���� ������ �ְ� ���̿켱 Ž�� ��ȯ

	friend ostream& operator<<(ostream&os, const AdjacentMatrix &g);

	void Dijkstra( int _start );				// ��������
	int extractMin();					// 
	void printShortestPath( int _start );	// ��� (���� ����)
	void printShortestPath(int _start, int _end);	// ��� (���� ���� -> �� ����)
};