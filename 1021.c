#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<bool> visit;
vector<int> rset;
set<int> fathest;
vector<int> dist;
int n, mdist;

int findRoot(int x)
{
	if (rset[x] == -1)
		return x;
	else
		return rset[x] = findRoot(rset[x]);
}

void bfs(int id)
{
	int i, index;
	queue<int> list;

	dist.assign(n + 1, 0);
	visit.assign(n + 1, false);
	list.push(id);
	dist[id] = 0;
	visit[id] = true;
	while (!list.empty()){
		index = list.front();
		list.pop();
		for (i = 0; i < tree[index].size(); i++){
			if (!visit[tree[index][i]]){
				list.push(tree[index][i]);
				dist[tree[index][i]] = dist[index] + 1;
				visit[tree[index][i]] = true;
			}
		}
	}
	mdist = dist[index];
}

int main()
{
	int i, a, b, r1, r2, gcount, root;

	cin >> n;
	tree.resize(n + 1);
	rset.assign(n + 1, -1);
	for (i = 1; i < n; i++){
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		r1 = findRoot(a);
		r2 = findRoot(b);
		if (r1 != r2)
			rset[r1] = r2;
	}
	gcount = 0;
	for (i = 1; i <= n; i++){
		if (rset[i] == -1)
			gcount++;
	}
	if (gcount > 1)
		printf("Error: %d components\n", gcount);
	else{
		root = 1;
		bfs(root);
		i = 1;
		for (i = 1; i <= n; i++){
			if (dist[i] == mdist)
				fathest.insert(i);
		}

		root = *fathest.begin();
		bfs(root);
		for (i = 1; i <= n; i++){
			if (dist[i] == mdist)
				fathest.insert(i);
		}
		for (set<int>::iterator it = fathest.begin(); it != fathest.end(); it++)
			cout << *it << endl;
	}
	return 0;
}