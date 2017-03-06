#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

struct TreeNode;
typedef TreeNode *Node;

int post[30], in[30];

struct TreeNode{
	int num;
	Node left, right;
};


Node buildTree(int pl, int pr, int il, int ir)
{
	int root;
	Node tmp;

	if (pl > pr)
		return NULL;
	root = il;
	while (in[root] != post[pr])
		root++;
	tmp = (Node)malloc(sizeof(TreeNode));
	tmp->num = in[root];
	tmp->left = buildTree(pl, pr - ir + root - 1, il, root - 1);
	tmp->right = buildTree(pr - ir + root, pr - 1, root + 1, ir);
	return tmp;
}

void levelPrint(Node root)
{
	queue<Node> list;
	Node t;

	printf("%d", root->num);
	if (root->left != NULL)
		list.push(root->left);
	if (root->right != NULL)
		list.push(root->right);

	while (!list.empty()){
		t = list.front();
		list.pop();
		printf(" %d", t->num);
		if (t->left != NULL)
			list.push(t->left);
		if (t->right != NULL)
			list.push(t->right);
	}
}

int main()
{

	int i, n;
	Node root;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &post[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &in[i]);

	root = buildTree(0, n-1, 0, n-1);
	levelPrint(root);
	return 0;
}