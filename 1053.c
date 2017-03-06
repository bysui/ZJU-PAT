#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<vector<int>> tree;
vector<int> sum, weight;
vector<int> path;
int n, m, s;

void print(int leaf)
{
	int i, len;

	len = path.size();
	for (i = 0; i < len; i++)
		printf("%d ", weight[path[i]]);
	printf("%d\n", weight[leaf]);
}

void dfs(int x)
{
	int i, len, id;

	len = tree[x].size();
	
	for (i = 0; i < len; i++){
		id = tree[x][i];
		sum[id] = sum[x] + weight[id];
		if (sum[id] == s){
			if (tree[id].size() == 0)
				print(id);
		}
		else if (sum[id] < s){
			path.push_back(id);
			dfs(id);
			path.pop_back();
		}
	}
}

bool comp(int a, int b)
{
	return weight[a] > weight[b];
}

int main()
{
	int i, j, id, cid, t;

	cin >> n >> m >> s;
	tree.resize(n);
	sum.assign(n, 0);
	weight.resize(n);
	for (i = 0; i < n; i++)
		cin >> weight[i];
	for (i = 0; i < m; i++){
		cin >> id >> t;
		for (j = 0; j < t; j++){
			cin >> cid;
			tree[id].push_back(cid);
		}
		sort(tree[id].begin(), tree[id].end(), comp);
	}
	if (n == 1 && weight[0] == s){
		printf("%d\n", s);
		return 0;
	}
	sum[0] = weight[0];
	path.push_back(0);
	dfs(0);
	return 0;
}