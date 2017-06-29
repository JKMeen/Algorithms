#include <iostream>
using namespace std;

enum { Ã¶¼ö = 0, ¿µÈñ, µ¿°Ç, ÁØÈ£, Àç»ó, ½Â¿ì };

typedef struct graphNode{
	int vertex;
	struct graphNode* link;
} graphNode;

class AdjacentList
{
private:
	int vertexMaxNumber;
	graphNode *adList;
	int numVertex;

public:
	AdjacentList(int num = 100);
	~AdjacentList();
	void insertVertex(int v);
	void insertEdge(int u, int v);
	int isAdjacent(int u, int v);
	int degree(int u);

	friend ostream& operator<<(ostream&os, const AdjacentList &g);
};