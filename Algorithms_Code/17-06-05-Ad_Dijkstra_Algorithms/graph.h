#include <iostream>
#include <iomanip>
using namespace std;
enum { 철수 = 0, 영희, 동건, 준호, 재상, 승우 };
class AdjacentMatrix
{
private:
	int vertexMaxNumber;
	int **adMatix;
	int numVertex;
	int *visit;
	int *dist;		// 거리
	bool *found;	// 찾음
	int **path;		// 중간 지점
	int *numPath;	// 중간 지점 갯수

public:
	AdjacentMatrix(int num = 100);
	~AdjacentMatrix();
	void insertVertex(int v);
	void insertEdge(int u, int v, int w);
	void insertEdge(int u, int v);
	bool isAdjacent(int v, int u);
	int  numDegree(int v);
	void DFS();			// 깊이 우선 탐색 시작
	void aDFS(int s);	// 시작 정점을 주고 깊이우선 탐색 순환

	friend ostream& operator<<(ostream&os, const AdjacentMatrix &g);

	void Dijkstra( int _start );				// 시작정점
	int extractMin();					// 
	void printShortestPath( int _start );	// 출력 (시작 정점)
	void printShortestPath(int _start, int _end);	// 출력 (시작 정점 -> 끝 정점)
};