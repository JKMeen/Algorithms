#include "adjacentMatrix.h"
#define INF 1000
AdjacentMatrix::AdjacentMatrix(int n)
{
	this->maxVertexNum = n;
	this->vertexnum = 0;

	this->Edge = new int*[n];
	for (int i = 0; i < n; i++)
	{
		this->Edge[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			this->Edge[i][j] = INF;
		}
	}
	this->vertexName = new string[n];
	visited = new bool[this->vertexnum];
	distance = new int[this->vertexnum];
}

AdjacentMatrix::~AdjacentMatrix()
{
	for (int i = 0; i < this->maxVertexNum; i++)
		delete[] this->Edge[i];
	delete[] this->Edge;
	/*delete[] visited;
	delete[] distance;*/
}

void AdjacentMatrix::insertVertex(int v, string name)
{
	if (v >= this->maxVertexNum)
	{
		cout << "Vertex Overflow" << endl;
		return;
	}
	this->vertexName[this->vertexnum] = name;
	this->vertexnum++;
}

void AdjacentMatrix::insertEdge(int u, int v, int w)
{
	if (u >= this->vertexnum || v >= this->vertexnum)
	{
		cout << "존재하지 않는 정점" << endl;
		return;
	}
	this->Edge[u][v] = w;
	this->Edge[v][u] = w;
}

int AdjacentMatrix::getDegree(int v)
{
	int degree = 0;
	for (int i = 0; i < this->vertexnum; i++)
		if (this->Edge[v][i] != 0) degree++;

	return degree;
}

void AdjacentMatrix::DFS()
{
	memset(visited, false, sizeof(bool)*this->vertexnum);

	for (int i = 0; i < this->vertexnum; i++)
	{
		if (!visited[i])
		{
			aDFS(i);
			cout << endl;
		}
	}
	delete[] visited;
}

void AdjacentMatrix::aDFS(int s)
{
	visited[s] = true;
	cout << s << " ";

	for (int i = 0; i < this->vertexnum; i++)
		if (this->Edge[s][i] == INF && !visited[i])
			aDFS(i);
}

int AdjacentMatrix::Prim(int s)
{
	memset(visited, false, sizeof(bool)*this->vertexnum);
	for (int i = 0; i < this->vertexnum; i++)
		this->distance[i] = INF;

	this->distance[s] = 0;
	for (int i = 0; i < this->vertexnum; i++)
	{
		int v = getMinDistance();
		cout << v << " ";
		visited[v] = true;
		for (int j = 0; j < this->vertexnum; j++)
		{
			if (!visited[j] && this->distance[j]>this->Edge[v][j])
				this->distance[j] = this->Edge[v][j];
		}
	}
	int cost = 0;
	for (int i = 0; i < this->vertexnum; i++)
		cost += this->distance[i];
	return cost;
}

int AdjacentMatrix::getMinDistance()
{
	int min_v, min_dist;

	min_v = min_dist = INF;
	for (int i = 0; i < this->vertexnum; i++)
	{
		if (!visited[i] && this->distance[i] < min_dist)
		{
			min_dist = this->distance[i];
			min_v = i;
		}
	}
	return min_v;
	delete[] distance;
}