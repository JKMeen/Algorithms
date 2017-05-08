#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
	int data;
	struct treenode *left;
	struct treenode*right;
}treeNode;

treeNode *root;

#endif