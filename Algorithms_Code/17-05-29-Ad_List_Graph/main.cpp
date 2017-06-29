#include "graph.h"

ostream& operator<<(ostream&os, const AdjacentList &g)
{
	graphNode* last;
	for (int i = 0; i < g.numVertex; i++){
		last = g.adList[i].link;
		os << "���� " << i << "  => ";
		while (last != NULL)
		{
			os << last->vertex << "  ";
			last = last->link;
		}
		os << endl;
	}
	return os;
}

int main()
{

	AdjacentList g1;

	for (int i = 0; i < 6; i++)
		g1.insertVertex(i);

	//�׷��� ǥ�� ������
	g1.insertEdge(ö��, ����); g1.insertEdge(����, ö��);
	g1.insertEdge(����, ����); g1.insertEdge(����, ����);
	g1.insertEdge(ö��, ����); g1.insertEdge(����, ö��);
	g1.insertEdge(ö��, ��ȣ); g1.insertEdge(��ȣ, ö��);
	g1.insertEdge(ö��, �¿�); g1.insertEdge(�¿�, ö��);
	g1.insertEdge(��ȣ, �¿�); g1.insertEdge(�¿�, ��ȣ);
	g1.insertEdge(���, �¿�); g1.insertEdge(�¿�, ���);
	g1.insertEdge(����, ���); g1.insertEdge(���, �¿�);

	cout << "���� ����Ʈ\n";
	cout << g1;

	cout << "ö���� ����� �ƴ� �����ΰ�?";
	if (g1.isAdjacent(ö��, ���)) cout << "�ƴ� �����̴�.\n";
	else cout << "�𸣴� �����̴�.\n";

	cout << "�¿��� ģ���� " << g1.degree(�¿�) << " ���̴�\n";
	return 0;
}