#include "BinarySearch.h"

treeNode* deleteNode(treeNode* r)
{
	treeNode* parent=NULL;
	if (r->left == NULL && r->right == NULL) return NULL; // ���1
	else if (r->left == NULL && r->right != NULL) return r->right; // ���2-1
	else if (r->left != NULL && r->right == NULL) return r->left; // ��� 2-2
	else // ��� 3
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
	if (r == t) // r�� ��Ʈ ����� ���
		root = deleteNode(t);
	else if (r == p->left) // r�� p�� ���� �ڽ�
		p->left = deleteNode(r);
	else  // r�� p�� ������ �ڽ�
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
		tmp = (treeNode*)malloc(sizeof(treeNode)); // tmp: �� ��� �Ҵ�
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
		printf("�̹� ���� Ű�� �ֽ��ϴ�. \n");
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
	printf("�������� ����?");
	scanf_s("%d", &n);
	printf("%d���� ���� �Է�:", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &data);
		//����Ž��Ʈ���� �߰�
	}
	inorder(root);  //��� Ȯ���� ����

	treeNode* tmp, *p;
	while (root != NULL)
	{
		printf("\n������ Ű �Է�:");
		scanf_s("%d", &data);
		tmp = treeSearch(root, data);
		p = treeSearchParent(root, data);
		//�����ϱ� ���� ��� 
		treeDelete(root, tmp, p);
		printf("\n������ ����Ž�����:\n");
		inorder(root);
	}

	free(root);
	return 0;
}