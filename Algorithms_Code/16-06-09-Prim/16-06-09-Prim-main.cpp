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
	string name[7] = { "ö��", "����", "����", "��ȣ", "���", "�¿�", "ȫ��"};

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


	cout << "�׷��� ���" << endl;
	cout << graph;

	cout << "������ �˰���"<<endl;
	int cost = graph.Prim(0);
	cout << endl;
	cout << "�ּҺ�� : "<< cost << endl;

	/*int vertex;
	while (1)
	{
		cout << "������ȣ: ";
		cin >> vertex;
		if (vertex < 0) break;
		cout << name[vertex] << "�� ������ " << graph.getDegree(vertex)<<endl;
	}*/

	/*cout << "���� �켱 Ž�� ��� \n";
	graph.DFS();*/

	return 0;
}