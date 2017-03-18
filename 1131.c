#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Station{
	vector<pair<int, int>> next;
}Station;

Station map[10000];
bool visit[10000];
int s1, s2;
int tlen, rlen;
vector<pair<int, int>> tpath, rpath;

void dfs(int x)
{
	int i, id, line;
	bool change;

	if (x == s2){
		if (tlen < rlen){
			rpath = tpath;
			rlen = tlen;
		}
		else if (tlen == rlen){
			if (tpath.size() < rpath.size())
				rpath = tpath;
		}
		return;
	}
	if (tlen >= rlen)
		return;
	
	for (i = 0; i < map[x].next.size(); ++i){
		id = map[x].next[i].first;
		line = map[x].next[i].second;
		change = false;
		if (!visit[id]){
			tlen++;
			if (tpath.back().second != line){
				tpath.push_back(make_pair(x, line));
				change = true;
			}
			visit[id] = true;
			dfs(id);
			tlen--;
			visit[id] = false;
			if (change)
				tpath.pop_back();
		}
	}
}

int main()
{
	int i, j, n, m, k, x1, x2;
	
	cin >> n;
	for (i = 1; i <= n; ++i){
		cin >> m;
		cin >> x1;
		for (j = 1; j < m; ++j){
			cin >> x2;
			map[x1].next.push_back(make_pair(x2, i));
			map[x2].next.push_back(make_pair(x1, i));
			x1 = x2;
		}
	}
	cin >> k;
	for (i = 0; i < k; ++i){
		cin >> s1 >> s2;
		tlen = 0;
		rlen = 10001;
		fill(visit, visit + 10000, false);
		visit[s1] = true;
		tpath.clear();
		rpath.clear();
		tpath.push_back(make_pair(s1, -1));
		dfs(s1);
		cout << rlen<<endl;
		for (j = 1; j < rpath.size() - 1; ++j)
			printf("Take Line#%d from %04d to %04d.\n", rpath[j].second, rpath[j].first, rpath[j + 1].first);
		printf("Take Line#%d from %04d to %04d.\n", rpath[j].second, rpath[j].first, s2);
	}
	return 0;
}