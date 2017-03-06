#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define Inf 1<<30

typedef struct{
	char name[4];
	int happy;
}City;

int n, k, romid;
int tcost, thappy, tlen, rcost, rhappy, rlen, rcount;
int roads[200][200];
City list[200];
int visit[200];
vector<int> troute, rroute;

int nameToid(char *name)
{
	int i;

	for (i = 0; i < n; i++)
		if (!strcmp(name, list[i].name))
			return i;
}

void dfs(int id)
{
	int i;

	if (id == romid){
		if (tcost == rcost){
			rcount++;
			if (thappy == rhappy){
				if (tlen < rlen){
					rlen = tlen;
					rroute = troute;
				}
			}
			else if (thappy > rhappy){
				rlen = tlen;
				rroute = troute;
				rhappy = thappy;
			}
		}
		else if (tcost < rcost){
			rcost = tcost;
			rlen = tlen;
			rroute = troute;
			rhappy = thappy;
			rcount = 1;
		}
		return;
	}

	for (i = 0; i < n; i++){
		if (roads[id][i] > 0 && !visit[i]){
			visit[i] = 1;
			tcost += roads[id][i];
			thappy += list[i].happy;
			tlen++;
			troute.push_back(i);
			dfs(i);
			visit[i] = 0;
			tcost -= roads[id][i];
			thappy -= list[i].happy;
			tlen--;
			troute.pop_back();
		}
	}
}

int main()
{
	int i, cost, n1, n2;
	char c1[4], c2[4];

	scanf("%d %d %s", &n, &k, list[0].name);
	list[0].happy = 0;
	for (i = 1; i < n; i++){
		scanf("%s %d", list[i].name, &list[i].happy);
		if (!strcmp(list[i].name, "ROM"))
			romid = i;
	}
	for (i = 0; i < k; i++){
		scanf("%s %s %d", c1, c2, &cost);
		n1 = nameToid(c1);
		n2 = nameToid(c2);
		roads[n1][n2] = roads[n2][n1] = cost;
	}

	tcost = thappy = 0;
	tlen = 0;
	rlen = rcost = Inf; 
	rcount = rhappy = 0;
	visit[0] = 1;
	troute.push_back(0);
	dfs(0);

	printf("%d %d %d %d\n", rcount, rcost, rhappy, rhappy / rlen);
	for (i = 0; i < rlen; i++)
		printf("%s->", list[rroute[i]].name);
	printf("%s\n", list[rroute[i]].name);
	return 0;
}