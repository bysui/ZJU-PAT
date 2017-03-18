#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct Node{
	string data;
	int left, right;
}Node;

vector<Node> tree;
int root;

void inOrder(int x)
{
	bool flag;

	if (tree[x].left == -1 && tree[x].right == -1 || x == root)
		flag = false;
	else
		flag = true;
	if (flag)
		cout << "(";
	if (tree[x].left != -1)
		inOrder(tree[x].left);
	cout << tree[x].data;
	if (tree[x].right != -1)
		inOrder(tree[x].right);
	if (flag)
		cout << ")";
}

int main()
{
	int i, n;

	vector<bool> isRoot;

	cin >> n;
	tree.resize(n + 1);
	isRoot.assign(n + 1, true);
	for (i = 1; i <= n; ++i){
		cin >> tree[i].data >> tree[i].left >> tree[i].right;
		if (tree[i].left != -1)
			isRoot[tree[i].left] = false;
		if (tree[i].right != -1)
			isRoot[tree[i].right] = false;
	}
	for (i = 1; i <= n; ++i){
		if (isRoot[i])
			break;
	}
	root = i;
	inOrder(root);
	return 0;
}