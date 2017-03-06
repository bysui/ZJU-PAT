#include <iostream>
#include <vector>
using namespace std;

#define Inf 1<<30

int n, m, start, target;
int mteam, mpath, mlen, tteam, tlen;
int road[500][500];
int reteam[500], visit[500];

void dfs(int id)
{
	int i;

	if (id == target){
		if (tlen == mlen){
			mpath++;
			if (tteam > mteam)
				mteam = tteam;
		}
		else if (tlen < mlen){
			mpath = 1;
			mteam = tteam;
			mlen = tlen;
		}
		return;
	}
	
	for (i = 0; i < n; i++){
		if (!visit[i] && road[id][i] > 0){
			tlen += road[id][i];
			tteam += reteam[i];
			visit[i] = 1;
			dfs(i);
			visit[i] = 0;
			tteam -= reteam[i];
			tlen -= road[id][i];
		}
	}
}

int main()
{
	int i, c1, c2, load;

	cin >> n >> m >> start >> target;
	for (i = 0; i < n; i++)
		cin >> reteam[i];
	for (i = 0; i < m; i++){
		cin >> c1 >> c2 >> load;
		road[c1][c2] = road[c2][c1] = load;
	}

	mpath = mteam = 0;
	mlen = Inf;
	tteam = reteam[start];
	tlen = 0;
	visit[start] = 1;
	dfs(start);

	printf("%d %d\n", mpath, mteam);
	return 0;
}