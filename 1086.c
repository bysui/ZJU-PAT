#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

struct TreeNode;
typedef struct TreeNode* Node;

struct TreeNode{
	int v;
	Node left, right;
};

vector<int> res;
int n;
int ncount;


Node buildTree()
{
	int id;
	Node node;
	char op[5];

	node = NULL;
	if (ncount < 2 * n){
		scanf("%s", op);
		if (op[1] == 'u'){
			scanf("%d", &id);
			node = (Node)malloc(sizeof(struct TreeNode));
			node->v = id;
			ncount++;
			node->left = buildTree();
			node->right = buildTree();
		}
		else{
			ncount++;
			return NULL;
		}
	}
	return node;
}

void postOrder(Node root)
{
	if (root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		res.push_back(root->v);
	}
}

int main()
{
	int i, id;
	Node root;

	scanf("%d", &n);
	ncount = 0;
	root = buildTree();
	postOrder(root);
	for (i = 0; i < n - 1; i++)
		printf("%d ", res[i]);
	printf("%d\n", res[i]);
	return 0;
}