#include <iostream>
#include <vector>
using namespace std;

#define Inf 1<<30

int road[500][500];
int cost[500][500];
int visit[500];
int n, m, s, d;
int tlen, tcost, rlen, rcost;
vector<int> tpath, rpath;

void dfs(int x)
{
	int i;

	if (x == d){
		if (tlen == rlen){
			if (tcost < rcost){
				rcost = tcost;
				rpath = tpath;
			}
		}
		else if (tlen < rlen){
			rlen = tlen;
			rcost = tcost;
			rpath = tpath;
		}
		return;
	}

	for (i = 0; i < n; i++){
		if (!visit[i] && road[x][i] != 0){
			tlen += road[x][i];
			tcost += cost[x][i];
			tpath.push_back(i);
			visit[i] = 1;
			dfs(i);
			tlen -= road[x][i];
			tcost -= cost[x][i];
			tpath.pop_back();
			visit[i] = 0;
		}
	}
}

int main()
{
	int i, a, b, dist, ct;

	cin >> n >> m >> s >> d;
	for (i = 0; i < m; i++){
		cin >> a >> b >> dist >> ct;
		road[a][b] = road[b][a] = dist;
		cost[a][b] = cost[b][a] = ct;
	}

	tcost = tlen = 0;
	rcost = rlen = Inf;
	visit[s] = 1;
	tpath.push_back(s);
	dfs(s);

	for (i = 0; i < rpath.size(); i++)
		cout << rpath[i] << " ";
	cout << rlen << " " << rcost << endl;
	return 0;
}