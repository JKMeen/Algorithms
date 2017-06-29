#include "graph.h"
#define INF 100000

AdjacentMatrix::AdjacentMatrix(int num)
{

	vertexMaxNumber = num;
	numVertex = 0;
	adMatix = new int*[num];
	dist = new int[num];
	found = new bool[num];
	path = new int*[num];
	numPath = new int[num];

	for (int i = 0; i < num; i++)	{
		adMatix[i] = new int[num];
		path[i] = new int[num];
		numPath[i] = 0;
		dist[i] = INF;
		found[i] = false;
	}

	for (int i = 0; i < num; i++)	{
		for (int j = 0; j < num; j++){
			path[i][j] = 0;
			adMatix[i][j] = INF;
			//memset(adMatix[i], INF, sizeof(int)*num);
		}
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
	//this->adMatix[v][u] = w; //=> 방향 그래프이기 때문에 주석처리
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


void AdjacentMatrix::Dijkstra(int _start){				// 시작정점
	for (int i = 0; i < this->numVertex; i++)	{
		dist[i] = INF;
		found[i] = false;
	}

	dist[_start] = 0;
	path[_start][numPath[_start]] = _start;

	for (int i = 0; i < this->numVertex; i++){
		int u = extractMin();
		if (u != INF){
			found[u] = true;
			for (int j = 0; j < this->numVertex; j++){
				if (this->adMatix[u][j] != INF){
					if (found[j] == false && dist[j] > dist[u] + this->adMatix[u][j]){
						dist[j] = dist[u] + this->adMatix[u][j];
						path[j][numPath[j]] = u;
						//numPath[j]++;
					}
				}
			}
		}
	}
}

int AdjacentMatrix::extractMin(){					// 최단 경로 찾기
	int min_dist = INF;	// 최소 거리 값 저장
	int min_v = INF;			// 반환할 거리
	for (int i = 0; i < this->numVertex; i++){
		if (found[i] == false && min_dist > dist[i]){
			min_dist = dist[i];
			min_v = i;
		}
	}
	return min_v;
}

void AdjacentMatrix::printShortestPath(int s){	// 출력 (시작 정점)
	for (int i = 0; i < this->numVertex; i++)
		cout << i << " 까지의 거리 >>> " << dist[i] << endl;

	cout << endl << "Path >>> " << s << endl;
	for (int i = 0; i < this->numVertex; i++){
		for (int j = 0; j <= numPath[i]; j++)
			cout << i << " 중간 정점 >>> " << path[i][j] << endl;
	}
}

void AdjacentMatrix::printShortestPath(int _start, int _end){
	if (path[_end][numPath[_end]] == INF){
		cout << "갈 수 없는 경로입니다" << endl;
		return;
	}
	else if (_start != path[_end][numPath[_end]])
		printShortestPath(_start, path[_end][numPath[_end]]);
	else cout << _start;

	cout << " - " << _end;
}