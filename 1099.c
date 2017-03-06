#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
	int key;
	int left, right;
};

int n, index;
vector<Node> tree;
vector<int> value;
vector<int> res;

void inOrder(int root)
{
	if (tree[root].left != -1)
		inOrder(tree[root].left);
	tree[root].key = value[index++];
	if (tree[root].right != -1)
		inOrder(tree[root].right);
}

void levelOrder(int root)
{
	int id;
	queue<int> list;

	list.push(root);
	while (!list.empty()){
		id = list.front();
		list.pop();
		res.push_back(id);
		if (tree[id].left != -1)
			list.push(tree[id].left);
		if (tree[id].right != -1)
			list.push(tree[id].right);
	}
}

int main()
{
	int i;

	cin >> n;
	tree.resize(n);
	value.resize(n);
	for (i = 0; i < n; i++)
		cin >> tree[i].left >> tree[i].right;
	for (i = 0; i < n; i++)
		cin >> value[i];
	
	sort(value.begin(), value.end());
	inOrder(0);

	levelOrder(0);
	for (i = 0; i < n - 1; i++)
		cout << tree[res[i]].key << " ";
	cout << tree[res[i]].key << endl;
	return 0;
}