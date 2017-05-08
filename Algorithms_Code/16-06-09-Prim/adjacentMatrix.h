#ifndef ADJACENTMATRIX_H
#define ADJACENTMATRIX_H
#include <iostream>
#include <iomanip>
#include<string>
using namespace std;

class AdjacentMatrix
{
private:
	int maxVertexNum;
	int vertexnum;
	int **Edge;
	string *vertexName;
	bool *visited;
	int *distance;
public:
	AdjacentMatrix(int num=100);
	~AdjacentMatrix();
	void insertVertex(int v, string name);
	void insertEdge(int u, int v, int w);
	int getDegree(int v);
	void DFS();
	void aDFS(int s);
	int Prim(int s);
	int getMinDistance();
	friend ostream& operator <<(ostream&os, const AdjacentMatrix &g);
};

#endif // !ADJACENTMATRIX_H