#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode;
typedef struct TreeNode* Node;

struct TreeNode{
	int value;
	Node left, right;
};
vector<int> post, pre, input;

Node Insert(int x, Node t, int mirror)
{
	if (t == NULL){
		t = (Node) malloc(sizeof(struct TreeNode));
		t->value = x;
		t->left = t->right = NULL;
	}
	else{
		if (!mirror){
			if (x < t->value)
				t->left = Insert(x, t->left, mirror);
			else
				t->right = Insert(x, t->right, mirror);
		}
		else{
			if (x >= t->value)
				t->left = Insert(x, t->left, mirror);
			else
				t->right = Insert(x, t->right, mirror);
		}
	}
	return t;
}

void postOrder(Node root)
{
	if (root->left != NULL)
		postOrder(root->left);
	if (root->right != NULL)
		postOrder(root->right);
	post.push_back(root->value);
}

void preOrder(Node root)
{
	pre.push_back(root->value);
	if (root->left != NULL)
		preOrder(root->left);
	if (root->right != NULL)
		preOrder(root->right);
	
}
int main()
{
	int v, i, n, mirror;	
	Node root;

	cin >> n;
	for (i = 0; i < n; i++){
		cin >> v;
		input.push_back(v);
	}
	if (input[0] > input[1])
		mirror = 0;
	else
		mirror = 1;
	root = NULL;
	for (i = 0; i < n; i++)
		root = Insert(input[i], root, mirror);
	preOrder(root);

	if (pre == input){
		printf("YES\n");
		postOrder(root);
		for (i = 0; i < n; i++){
			if (i == n - 1)
				cout << post[i] << endl;
			else
				cout << post[i] << " ";

		}
	}
	else
		printf("NO\n");

	return 0;
}