#include "graph.h"

ostream& operator<<(ostream&os, const AdjacentList &g)
{
	graphNode* last;
	for (int i = 0; i < g.numVertex; i++){
		last = g.adList[i].link;
		os << "Á¤Á¡ " << i << "  => ";
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

	//±×·¡ÇÁ Ç¥Çö µ¥ÀÌÅÍ
	g1.insertEdge(Ã¶¼ö, ¿µÈñ); g1.insertEdge(¿µÈñ, Ã¶¼ö);
	g1.insertEdge(¿µÈñ, µ¿°Ç); g1.insertEdge(µ¿°Ç, ¿µÈñ);
	g1.insertEdge(Ã¶¼ö, µ¿°Ç); g1.insertEdge(µ¿°Ç, Ã¶¼ö);
	g1.insertEdge(Ã¶¼ö, ÁØÈ£); g1.insertEdge(ÁØÈ£, Ã¶¼ö);
	g1.insertEdge(Ã¶¼ö, ½Â¿ì); g1.insertEdge(½Â¿ì, Ã¶¼ö);
	g1.insertEdge(ÁØÈ£, ½Â¿ì); g1.insertEdge(½Â¿ì, ÁØÈ£);
	g1.insertEdge(Àç»ó, ½Â¿ì); g1.insertEdge(½Â¿ì, Àç»ó);
	g1.insertEdge(µ¿°Ç, Àç»ó); g1.insertEdge(Àç»ó, ½Â¿ì);

	cout << "ÀÎÁ¢ ¸®½ºÆ®\n";
	cout << g1;

	cout << "Ã¶¼ö¿Í Àç»óÀº ¾Æ´Â »çÀÌÀÎ°¡?";
	if (g1.isAdjacent(Ã¶¼ö, Àç»ó)) cout << "¾Æ´Â »çÀÌÀÌ´Ù.\n";
	else cout << "¸ð¸£´Â »çÀÌÀÌ´Ù.\n";

	cout << "½Â¿ìÀÇ Ä£±¸´Â " << g1.degree(½Â¿ì) << " ¸íÀÌ´Ù\n";
	return 0;
}