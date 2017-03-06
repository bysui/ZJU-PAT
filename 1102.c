#include<iostream>
#include <string>
#include <queue>
#include<vector>
using namespace std;

typedef struct TreeNode{
	int left, right, parent;
	TreeNode(){
		left = right = parent = -1;
	}
}Node;

int n;
vector<Node> tree;
bool infirst;

void levelOrder(int root)
{
	int id;
	queue<int> list;
	bool first;

	first = true;
	list.push(root);
	while (!list.empty()){
		id = list.front();
		list.pop();
		if (first){
			printf("%d", id);
			first = false;
		}
		else
			printf(" %d", id);
		if (tree[id].left != -1)
			list.push(tree[id].left);
		if (tree[id].right != -1)
			list.push(tree[id].right);
	}
}

void inOrder(int root)
{
	if (tree[root].left != -1)
		inOrder(tree[root].left);
	if (infirst){
		printf("%d", root);
		infirst = false;
	}
	else
		printf(" %d", root);
	if (tree[root].right != -1)
		inOrder(tree[root].right);
}

int main()
{
	int i, j, id, cnt, root;
	string str;

	cin >> n;
	tree.resize(n);
	getchar();
	for (i = 0; i < n; i++){
		getline(cin, str);
		if (str[0] != '-'){
			id = str[0] - '0';
			tree[i].right = id;
			tree[id].parent = i;
		}
		if (str[2] != '-'){
			id = str[2] - '0';
			tree[i].left = id;
			tree[id].parent = i;
		}
	}
	for (i = 0; i < n; i++){
		if (tree[i].parent == -1){
			root = i;
			break;
		}
	}

	levelOrder(root);
	printf("\n");
	infirst = true;
	inOrder(root);
	printf("\n");
	return 0;
}