#include "graph.h"
ostream& operator<<(ostream&os, const AdjacentMatrix &g)
{
	os << setw(4) << "     ";
	for (int i = 0; i < g.numVertex; i++)
		os << setw(4) << "<" << i << ">  ";
	os << endl;

	for (int i = 0; i < g.numVertex; i++){
		os << "<" << i << ">  ";
		for (int j = 0; j < g.numVertex; j++)
			os << setw(7) << g.adMatix[i][j] << " ";
		os << endl;
	}
	return os;
}

int main()
{
	AdjacentMatrix g;
	for (int i = 0; i < 8; i++)
		g.insertVertex(i);

	g.insertEdge(0, 1,  11);
	g.insertEdge(0, 2,   9);
	g.insertEdge(0, 3,   8);
	
	g.insertEdge(1, 4,   8);
	g.insertEdge(1, 6,   8);
	
	g.insertEdge(2, 1,   3);
	g.insertEdge(2, 3,   6);
	g.insertEdge(2, 5,   1);

	g.insertEdge(3, 5,  10);

	g.insertEdge(4, 6,   7);

	g.insertEdge(5, 7,   2);

	g.insertEdge(6, 2,  12);
	g.insertEdge(6, 7,   5);

	g.insertEdge(7, 4,   4);


	cout << g << endl; // 출력

	int start;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "시작 정점 입력 >>> ";
	cin >> start;

	g.Dijkstra(start);
	g.printShortestPath(start);
	cout << endl;

	while (1){
		int dest_v;
		cout << "--------------------------------------------------------------------" << endl;
		cout << "목적지 입력 (종료 -1) >>> ";
		cin >> dest_v;
		if (dest_v < 0) break;

		g.printShortestPath(start, dest_v);
		cout << endl;
	}
	return 0;
}