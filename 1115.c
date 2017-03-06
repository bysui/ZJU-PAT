#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode;
typedef struct TreeNode* Node;

struct TreeNode{
	Node left, right;
	int val;
	TreeNode(int v) :left(NULL), right(NULL), val(v){}
};

int n, last;
Node root;

Node insert(Node n, int val)
{
	if (n == NULL){
		n = new TreeNode(val);
		return n;
	}
	if (val <= n->val)
		n->left= insert(n->left, val);
	else
		n->right = insert(n->right, val);
	return n;
}

int main()
{
	int i, j, val, n1, n2;
	queue<Node> list;
	Node tmp;

	cin >> n;
	for (i = 0; i < n; i++){
		cin >> val;
		root = insert(root, val);
	}

	list.push(root);
	n1 = n2 = 0;
	while (!list.empty()){
		n2 = n1;
		n1 = list.size();
		for (i = 0; i < n1; i++){
			tmp = list.front();
			list.pop();
			if (tmp->left)
				list.push(tmp->left);
			if (tmp->right)
				list.push(tmp->right);
		}
	}
	printf("%d + %d = %d\n", n1, n2, n1 + n2);
	return 0;
}