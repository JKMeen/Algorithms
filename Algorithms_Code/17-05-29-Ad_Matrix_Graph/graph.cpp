#include "graph.h"
#define INF 10000

AdjacentMatrix::AdjacentMatrix(int num)
{

	vertexMaxNumber = num;
	numVertex = 0;
	adMatix = new int*[num];
	for (int i = 0; i < num; i++)	{
		adMatix[i] = new int[num];
	}
	for (int i = 0; i < num; i++)	{
		memset(adMatix[i], 0, sizeof(int)*num);
	}

}

AdjacentMatrix::~AdjacentMatrix()
{
	for (int i = 0; i < this->vertexMaxNumber; i++)
		delete[] adMatix[i];
	delete[] adMatix;

}

void AdjacentMatrix::insertVertex(int v){
	if (v >= this->vertexMaxNumber){
		cout << "정점 초과오류!\n";
		return;
	}
	this->numVertex++;
}

void AdjacentMatrix::insertEdge(int u, int v, int w){
	if (u >= this->vertexMaxNumber || v >= this->vertexMaxNumber){
		cout << "그런 정점이 없습니다.\n"; return;
	}

	this->adMatix[u][v] = w;
	this->adMatix[v][u] = w;
}

void AdjacentMatrix::insertEdge(int u, int v){
	if (u >= this->vertexMaxNumber || v >= this->vertexMaxNumber){
		cout << "그런 정점이 없습니다.\n"; return;
	}

	// 무향 그래프이기 때문에 서로를 이어준다.
	this->adMatix[u][v] = 1;
	this->adMatix[v][u] = 1;
}

bool AdjacentMatrix::isAdjacent(int v, int u){
	if (u >= this->vertexMaxNumber || v >= this->vertexMaxNumber){
		cout << "그런 정점이 없습니다.\n"; return false;
	}

	return this->adMatix[v][u];
}

int  AdjacentMatrix::numDegree(int v){
	if (v >= this->vertexMaxNumber){
		cout << "그런 정점이 없습니다.\n"; return 0;
	}

	int num = 0;
	for (int i = 0; i < this->numVertex; i++){
		if (this->adMatix[v][i] == 1)
			num++;
	}
	return num;
}

void AdjacentMatrix::DFS(){
	this->visit = new int[this->numVertex]; // 동적 할당
	for (int i = 0; i < this->numVertex; i++)
		this->visit[i] = false;

	for (int i = 0; i < this->numVertex; i++)
	if (this->visit[i] != true) aDFS(i);
}

void AdjacentMatrix::aDFS(int s){
	this->visit[s] = true;
	cout << s << " ";
	for (int i = 0; i < this->numVertex; i++)
		if (this->adMatix[s][i] != 0 && !this->visit[i])
			aDFS(i);
}