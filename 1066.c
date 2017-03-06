#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode* Node;


struct TreeNode{
	int val;
	int height;
	Node left, right;
};

Node treeRoot;

static int Height(Node P)
{
	if (P == NULL)
		return -1;
	else
		return P->height;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

Node SingleRotateWithLeft(Node k2)
{
	Node k1;

	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
	k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
	return k1;
}

Node SingleRotateWithRight(Node k2)
{
	Node k1;

	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
	k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
	return k1;
}

Node DoubleRotateWithLeft(Node k3)
{
	k3->left = SingleRotateWithRight(k3->left);
	return SingleRotateWithLeft(k3);
}

Node DoubleRotateWithRight(Node k3)
{
	k3->right = SingleRotateWithLeft(k3->right);
	return SingleRotateWithRight(k3);
}

Node Insert(Node root, int val)
{
	if (root == NULL){
		root = (Node)malloc(sizeof(struct TreeNode));
		root->val = val;
		root->height = 0;
		root->left = root->right = NULL;
	}
	else{
		if (val < root->val){
			root->left = Insert(root->left, val);
			if (Height(root->left) - Height(root->right) == 2)
				if (val < root->left->val)
					root = SingleRotateWithLeft(root);
				else
					root = DoubleRotateWithLeft(root);
		}
		else if (val > root->val){
			root->right = Insert(root->right, val);
			if (Height(root->right) - Height(root->left) == 2)
				if (val > root->right->val)
					root = SingleRotateWithRight(root);
				else
					root = DoubleRotateWithRight(root);
		}
	}
	root->height = Max(Height(root->left), Height(root->right)) + 1;
	return root;
}

int main()
{
	int i, val, n;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &val);
		treeRoot = Insert(treeRoot, val);
	}
	printf("%d\n", treeRoot->val);
	return 0;
}