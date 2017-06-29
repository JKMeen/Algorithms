#include "graph.h"

AdjacentList::AdjacentList(int num)
{
	vertexMaxNumber = num;

	numVertex = 0;
	adList = new graphNode[num];
	for (int i = 0; i < num; i++)
	{
		adList[i].link= NULL;
	}
}

AdjacentList::~AdjacentList()
{
	delete[] adList;
}


void AdjacentList::insertVertex(int v)
{
	if (numVertex > vertexMaxNumber){
		printf("\n �׷��� ������ ������ �ʰ�!");
		return;
	}
	this->numVertex++;
}

void AdjacentList::insertEdge(int u, int v)
{
	if (u >= numVertex || v >= numVertex) {
		printf("\n �׷����� ���� �����Դϴ�!");
		return;
	}
	graphNode*node, *last;
	node = new graphNode;
	last = adList[u].link;
	node->vertex = v;
	node->link = last;
	adList[u].link = node;
}


int AdjacentList::isAdjacent(int u, int v)
{
	graphNode *last = this->adList[u].link;
	while (last != NULL) {
		if (last->vertex == v)
			return true;
		else last = last->link;
	}
	return false;
}

int AdjacentList::degree(int u)
{
	int count = 0;
	graphNode *last = this->adList[u].link;
	while (last != NULL) {
		count++;
		last = last->link;
	}
	return count;
}


