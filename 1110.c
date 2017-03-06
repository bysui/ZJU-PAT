#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef struct Node{
	int left, right;
	int parent;
	Node() :left(-1), right(-1), parent(-1){}
}Node;

int n, root, last;
vector<Node> tree;

bool isCompleteTree(int x)
{
	queue<int> list;
	int cur, index;

	list.push(x);
	index = 0;
	while ((cur = list.front()) != -1){
		list.pop();
		index++;
		last = cur;
		list.push(tree[last].left);
		list.push(tree[last].right);
	}
	if (index == n)
		return true;
	else
		return false;
}

int main()
{
	int i, j, id;
	string sid;

	cin >> n;
	tree.resize(n);
	for (i = 0; i < n; i++){
		cin >> sid;
		if (sid[0] != '-'){
			id = atoi(sid.c_str());
			tree[i].left = id;
			tree[id].parent = i;
		}
		cin >> sid;
		if (sid[0] != '-'){
			id = atoi(sid.c_str());
			tree[i].right = id;
			tree[id].parent = i;
		}
	}
	
	for (i = 0; i < n; i++){
		if (tree[i].parent == -1){
			root = i;
			break;
		}
	}

	if (isCompleteTree(root))
		cout << "YES " << last << endl;
	else
		cout << "NO " << root << endl;
	return 0;
}