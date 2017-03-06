#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode;
typedef struct TreeNode* Node;

struct TreeNode{
	int val;
	Node left, right;
	TreeNode(int v){
		val = v;
		left = right = NULL;
	}
};

int n;
vector<int> in, post;
vector<int> level;
vector<vector<int>> res;

Node buildTree(Node t, int il, int ir, int pl, int pr)
{
	int i, root, index;

	if (il > ir)
		return NULL;
	root = post[pr];
	for (i = 0; i < n; i++){
		if (in[i] == root){
			index = i;
			break;
		}
	}
	if (t == NULL)
		t = new TreeNode(root);
	t->left = buildTree(t->left, il, index - 1, pl, pl + index - il - 1);
	t->right = buildTree(t->right, index + 1, ir, pl + index - il, pr - 1);
	return t;
}

void levelOrder(Node root)
{
	queue<Node> list;
	Node tmp, last;
	bool first;
	int i, j;

	list.push(root);
	last = root;
	first = true;
	while (!list.empty()){
		tmp = list.front();
		list.pop();
		if (tmp == last){
			first = false;
			res.push_back(level);
			level.clear();
		}
		level.push_back(tmp->val);
		if (tmp->left){
			list.push(tmp->left);
			if (!first){
				first = true;
				last = tmp->left;
			}
		}
		if (tmp->right){
			list.push(tmp->right);
			if (!first){
				first = true;
				last = tmp->right;
			}
		}
	}
	res.push_back(level);
	cout << res[1][0];
	for (i = 2; i < res.size(); i++){
		if (i % 2 == 1){
			for (j = res[i].size() - 1; j >= 0; j--)
				cout << " " << res[i][j];
		}
		else{
			for (j = 0; j < res[i].size(); j++)
				cout << " " << res[i][j];
		}
	}
}

int main()
{
	int i;
	Node root;
	
	cin >> n;
	in.resize(n);
	post.resize(n);
	for (i = 0; i < n; i++)
		cin >> in[i];
	for (i = 0; i < n; i++)
		cin >> post[i];
	root = NULL;
	root = buildTree(root, 0, n - 1, 0, n - 1);
	levelOrder(root);
	return 0;
}