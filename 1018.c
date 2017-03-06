#include <iostream>
#include <vector>
using namespace std;

#define Inf 1<<30

int road[501][501];
int bike[501];
bool visit[501];
int cmax, n, sp, m;
int tdist, tsend, tback, rdist, rsend, rback;
vector<int> tpath, rpath;

void dfs(int x)
{
	int i, b, s;

	if (x == sp){
		if (tdist == rdist){
			if (tsend == rsend){
				if (tback < rback){
					rback = tback;
					rpath = tpath;
				}
			}
			else if (tsend < rsend){
				rsend = tsend;
				rback = tback;
				rpath = tpath;
			}
		}
		else if(tdist < rdist){
			rdist = tdist;
			rsend = tsend;
			rback = tback;
			rpath = tpath;
		}
		return;
	}
	for (i = 1; i <= n; i++){
		if (!visit[i] && road[x][i] != 0){
			b = tback;
			s = tsend;
			visit[i] = true;
			if (bike[i] < cmax){
				if (tback + bike[i] >= cmax)
					tback -= cmax - bike[i];
				else{
					tsend += cmax - bike[i] - tback;
					tback = 0;
				}
			}
			else
				tback += bike[i] - cmax;
			tdist += road[x][i];
			tpath.push_back(i);
			dfs(i);
			visit[i] = false;
			tback = b;
			tsend = s;
			tdist -= road[x][i];
			tpath.pop_back();
		}
	}
}

int main()
{
	int i, s1, s2, dist;

	cin >> cmax >> n >> sp >> m;
	for (i = 1; i <= n; i++)
		cin >> bike[i];
	for (i = 0; i < m; i++){
		cin >> s1 >> s2 >> dist;
		road[s1][s2] = road[s2][s1] = dist;
	}
	cmax /= 2;
	tdist = tsend = tback = 0;
	tpath.push_back(0);
	rdist = Inf;
	visit[0] = true;
	dfs(0);

	printf("%d ", rsend);
	for (i = 0; i < rpath.size() - 1; i++)
		printf("%d->", rpath[i]);
	printf("%d %d\n", rpath[i], rback);
	return 0;
}