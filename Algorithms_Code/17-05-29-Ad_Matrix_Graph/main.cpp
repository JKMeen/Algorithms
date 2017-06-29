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

	g.insertEdge(ö��, ����);
	g.insertEdge(ö��, ����);
	g.insertEdge(ö��, ��ȣ);
	g.insertEdge(ö��, �¿�);
	g.insertEdge(����, ����);
	g.insertEdge(����, ���);
	g.insertEdge(���, �¿�);
	g.insertEdge(��ȣ, �¿�);
	
	cout << g; // ���

	if (g.isAdjacent(��ȣ, ���))
		cout << "��ȣ�� ����� ģ����. \n";
	else
		cout << "��ȣ�� ����� ģ���� �ƴϴ�. \n";

	cout << "��ȣ�� ģ����" << g.numDegree(��ȣ) << "�� �̴�.\n";

	g.DFS();

	return 0;	
}