#include"adjacentMatrix.h"

ostream& operator <<(ostream&os, const AdjacentMatrix &g)
{
	for (int i = 0; i < g.vertexnum; i++)
	{
		os << g.vertexName[i] << " : ";
		for (int j = 0; j < g.vertexnum; j++)
		{
			os << setw(5) <<g.Edge[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

int main()
{
	AdjacentMatrix graph(50);
	string name[7] = { "철수", "영희", "동건", "준호", "재상", "승우", "홍길"};

	for (int i = 0; i < 7; i++)
		graph.insertVertex(i, name[i]);
	graph.insertEdge(0, 1, 8); graph.insertEdge(1, 0, 8);
	graph.insertEdge(0, 2, 9); graph.insertEdge(2, 0, 9);
	graph.insertEdge(0, 3, 11); graph.insertEdge(3, 0, 11);
	graph.insertEdge(1, 5, 10); graph.insertEdge(5, 1, 10);
	graph.insertEdge(2, 5, 5); graph.insertEdge(5, 2, 5);
	graph.insertEdge(2, 3, 13); graph.insertEdge(3, 2, 13);
	graph.insertEdge(3, 4, 8); graph.insertEdge(4, 3, 8);
	graph.insertEdge(4, 6, 7); graph.insertEdge(6, 4, 7);
	graph.insertEdge(2, 6, 12); graph.insertEdge(6, 2, 12);


	cout << "그래프 출력" << endl;
	cout << graph;

	cout << "프림의 알고리즘"<<endl;
	int cost = graph.Prim(0);
	cout << endl;
	cout << "최소비용 : "<< cost << endl;

	/*int vertex;
	while (1)
	{
		cout << "정점번호: ";
		cin >> vertex;
		if (vertex < 0) break;
		cout << name[vertex] << "의 차수는 " << graph.getDegree(vertex)<<endl;
	}*/

	/*cout << "깊이 우선 탐색 결과 \n";
	graph.DFS();*/

	return 0;
}