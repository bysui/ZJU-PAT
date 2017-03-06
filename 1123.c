#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode;
typedef struct TreeNode* Node;

struct TreeNode{
	int val, height;
	Node left, right;
	TreeNode(int v){
		left = right = NULL;
		val = v;
		height = 0;
	}
};

int n;
vector<Node> res;

int getHeight(Node n)
{
	if (n == NULL)
		return -1;
	else
		return n->height;
}

Node singleRotationWithLeft(Node k2)
{
	Node k1;

	k1 = k2->left;
	k2 ->left = k1->right;
	k1->right = k2;
	k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
	k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
	return k1;
}

Node singleRotationWithRight(Node k2)
{
	Node k1;

	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
	k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
	return k1;
}

Node doubleRotationWithLeft(Node k3)
{
	k3->left = singleRotationWithRight(k3->left);
	return singleRotationWithLeft(k3);
}

Node doubleRotationWithRight(Node k3)
{
	k3->right = singleRotationWithLeft(k3->right);
	return singleRotationWithRight(k3);
}

Node insert(Node root, int x)
{
	if (root == NULL){
		root = new TreeNode(x);
		return root;
	}

	if (x < root->val){
		root->left = insert(root->left, x);
		if (getHeight(root->left) - getHeight(root->right) == 2){
			if (x < root->left->val)
				root = singleRotationWithLeft(root);
			else
				root = doubleRotationWithLeft(root);
		}
	}
	else if (x > root->val){
		root->right = insert(root->right, x);
		if (getHeight(root->right) - getHeight(root->left) == 2){
			if (x > root->right->val)
				root = singleRotationWithRight(root);
			else
				root = doubleRotationWithRight(root);
		}
	}
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	return root;
}

void levelOrder(Node root)
{
	queue<Node> list;
	Node tmp;
	int i, count;
	bool isOk;

	list.push(root);
	count = 1;
	isOk = true;
	while (!list.empty()){
		tmp = list.front();
		list.pop();
		res.push_back(tmp);
		if (tmp->left){
			list.push(tmp->left);
			count++;
		}
		else if (isOk && count < n)
			isOk = false;
		if (tmp->right){
			list.push(tmp->right);
			count++;
		}
		else if (isOk && count < n)
			isOk = false;
	}
	cout << res[0]->val;
	for (i = 1; i < n; i++)
		cout << " " << res[i]->val;
	cout << endl;
	if (isOk)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main()
{
	int i, j, val;
	Node root;

	cin >> n;
	root = NULL;
	for (i = 0; i < n; i++){
		cin >> val;
		root = insert(root, val);
	}
	
	levelOrder(root);
	return 0;
}