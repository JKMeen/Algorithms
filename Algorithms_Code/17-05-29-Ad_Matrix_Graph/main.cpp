#include "graph.h"
ostream& operator<<(ostream&os, const AdjacentMatrix &g)
{
	for (int i = 0; i < g.numVertex; i++){
		for (int j = 0; j < g.numVertex; j++)
			os << setw(4) << g.adMatix[i][j] << " ";
		os << endl;
	}
	return os;
}

int main()
{
	AdjacentMatrix g;
	for (int i = 0; i < 6; i++)
		g.insertVertex(i);

	g.insertEdge(철수, 영희);
	g.insertEdge(철수, 동건);
	g.insertEdge(철수, 준호);
	g.insertEdge(철수, 승우);
	g.insertEdge(영희, 동건);
	g.insertEdge(동건, 재상);
	g.insertEdge(재상, 승우);
	g.insertEdge(준호, 승우);
	
	cout << g; // 출력

	if (g.isAdjacent(준호, 재상))
		cout << "준호와 재상은 친구다. \n";
	else
		cout << "준호와 재상은 친구가 아니다. \n";

	cout << "준호의 친구는" << g.numDegree(준호) << "명 이다.\n";

	g.DFS();

	return 0;	
}