#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Inf 1<<30

int n, m, src, dest;
int map[500][500], cost[500][500];
int dist1[500], dist2[500], path1[500], path2[500];
bool visit[500];

void Dijskra(int mp1[][500], int mp2[][500], int d1[], int path[])
{
	int i, cur, min;
	int d2[500];

	for (i = 0; i < n; i++){
		visit[i] = false;
		d1[i] = mp1[src][i];
		d2[i] = mp2[src][i];
		path[i] = src;
	}
	visit[src] = true;
	d1[src] = d2[src] = 0;
	cur = src;
	while (cur != dest){
		min = Inf;
		for (i = 0; i < n; i++){
			if (!visit[i] && d1[i] < min){
				min = d1[i];
				cur = i;
			}
		}
		visit[cur] = true;
		for (i = 0; i < n; i++){
			if (!visit[i]){
				if (d1[cur] + mp1[cur][i] < d1[i]){
					d1[i] = d1[cur] + mp1[cur][i];
					d2[i] = d2[cur] + mp2[cur][i];
					path[i] = cur;
				}
				else if (d1[cur] + mp1[cur][i] == d1[i] && d2[cur] + mp2[cur][i] < d2[i]){
					d2[i] = d2[cur] + mp2[cur][i];
					path[i] = cur;
				}
			}
		}
	}
}

void printPath(int path[])
{
	int i;
	vector<int> res;

	if (src == dest)
		printf(" -> %d", dest);
	else{
		i = dest;
		while (i != src){
			res.insert(res.begin(), i);
			i = path[i];
		}
		for (i = 0; i < res.size(); i++)
			printf(" -> %d", res[i]);
	}
	printf("\n");
}

int main()
{
	int i, j, v1, v2, oneway, length, time;
	int cnt[500][500];

	cin >> n >> m;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			map[i][j] = cost[i][j] = Inf;
			cnt[i][j] = 1;
		}
	}
	for (i = 0; i < m; i++){
		cin >> v1 >> v2 >> oneway >> length >> time;
		map[v1][v2] = length;
		cost[v1][v2] = time;
		if (!oneway){
			map[v2][v1] = length;
			cost[v2][v1] = time;
		}
	}
	cin >> src >> dest;
	Dijskra(map, cost, dist1, path1);
	Dijskra(cost, cnt, dist2, path2);
	i = dest;
	while (i != src && path1[i] == path2[i])
		i = path1[i];
	if (i == src){
		printf("Distance = %d; Time = %d: %d", dist1[dest], dist2[dest], src);
		printPath(path1);
	}
	else{
		printf("Distance = %d: %d", dist1[dest], src);
		printPath(path1);
		printf("Time = %d: %d", dist2[dest], src);
		printPath(path2);
		
	}
	return 0;
}