#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

TreeNode n1={1, NULL, NULL};
TreeNode n2={4, &n1, NULL};
TreeNode n3={16, NULL, NULL};
TreeNode n4={25, NULL, NULL};
TreeNode n5={20, &n3, &n4};
TreeNode n6={15, &n2, &n5};
TreeNode *root= &n6;

void inorder( TreeNode *root ){
   if ( root ){
       inorder( root->left ); // 왼쪽서브트리 순회
       printf("%3d", root->data ); // 노드 방문
      inorder( root->right ); //오른쪽서브트리 순회
	}
}
// 전위 순회
void preorder( TreeNode *root ){
   if ( root ){
       printf("%3d", root->data) ; //노드 방문
       preorder( root->left ); //왼쪽서브트리 순회
       preorder( root->right ); //오른쪽서브트리 순회
	}
}
void postorder( TreeNode *root ){
    if ( root ){
         postorder( root->left );	 // 왼쪽서브트리 순회
         postorder( root->right );  // 오른쪽서브트리순회
         printf("%3d", root->data );  // 노드 방문
	}
}

void main()
{
    printf("##중위순회 결과: ");   inorder(root);
    printf("\n##전위순회 결과: ");   preorder(root);
    printf("\n##후위순회 결과: ");   postorder(root);
	getchar();
}
