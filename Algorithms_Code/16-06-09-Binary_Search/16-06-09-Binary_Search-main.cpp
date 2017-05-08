#include "BinarySearch.h"

treeNode* deleteNode(treeNode* r)
{
	treeNode* parent=NULL;
	if (r->left == NULL && r->right == NULL) return NULL; // 경우1
	else if (r->left == NULL && r->right != NULL) return r->right; // 경우2-1
	else if (r->left != NULL && r->right == NULL) return r->left; // 경우 2-2
	else // 경우 3
	{
		treeNode* s = r->right;
		while (s->left != NULL)
		{
			parent = s; s = s->left;
		}
		r->data = s->data;
		if (s == r->right)
			r->right = s->right;
		else parent->left = s->right;
		return r;
	}
}


void treeDelete(treeNode*t, treeNode*r, treeNode*p)
{
	if (r == t) // r이 루트 노드인 경우
		root = deleteNode(t);
	else if (r == p->left) // r이 p의 왼쪽 자식
		p->left = deleteNode(r);
	else  // r이 p의 오른쪽 자식
		p->right = deleteNode(r);
}

treeNode* treeSearch(treeNode* t, int x)
{
	if (t == NULL || t->data == x)
		return t;
	if (x < t->data)
		return treeSearch(t->left, x);
	else
		return treeSearch(t->right, x);
}


treeNode* treeInsert(treeNode* t, int x)
{
	treeNode *tmp;
	if (t == NULL)
	{
		tmp = (treeNode*)malloc(sizeof(treeNode)); // tmp: 새 노드 할당
		tmp->data = x; tmp->left = tmp->right = NULL;
		return tmp;
	}
	if (x < t->data)
	{
		t->left = treeInsert(t->left, x);
		return t;
	}
	else if (x > t->data)
	{
		t->right = treeInsert(t->right, x);
		return t;
	}
	else {
		printf("이미 같은 키가 있습니다. \n");
		return t;
	}
}

void inorder(treeNode* r)
{
	if (r != NULL)
	{
		inorder(r->left);
		printf("%d ", r->data);
		inorder(r->right);
	}
}

treeNode* treeSearchParent(treeNode*r, int data)
{
	treeNode *p;
	p = NULL;
	while (r != NULL)
	{
		if (r->data == data) break;
		else if (r->data < data)
		{
			p = r;
			r = r->right;
		}
		else
		{
			p = r;
			r = r->left;
		}

	}

	return p;
}

int main()
{
	int n, data;

	root = NULL;
	printf("데이터의 개수?");
	scanf_s("%d", &n);
	printf("%d개의 정수 입력:", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &data);
		//이진탐색트리에 추가
	}
	inorder(root);  //결과 확인을 위해

	treeNode* tmp, *p;
	while (root != NULL)
	{
		printf("\n삭제할 키 입력:");
		scanf_s("%d", &data);
		tmp = treeSearch(root, data);
		p = treeSearchParent(root, data);
		//삭제하기 위한 명령 
		treeDelete(root, tmp, p);
		printf("\n삭제후 이진탐색노드:\n");
		inorder(root);
	}

	free(root);
	return 0;
}