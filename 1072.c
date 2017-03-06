#include <stdio.h>
#include <string.h>

#define Inf 1<<30

typedef struct{
	int total;
	int dmin;
	int isOK;
}GasNode;

int n, m, k, d;
int map[1011][1011];
int vist[1011], dist[1011];
GasNode list[10];

int strToint(char *str)
{
	int i, len, sum;

	len = strlen(str);
	sum = 0;
	for (i = 0; i < len; i++)
		sum = sum * 10 + str[i] - '0';
	return sum;
}

void Dijstra(int src)
{
	int i, j, k, dmax;

	dist[src] = 0;
	for (i = 1; i < n + m; i++){
		dmax = Inf;
		for (j = 1; j <= 1000 + m; j++){
			if (!vist[j] && dist[j] < dmax){
				dmax = dist[j];
				k = j;
			}
			if (j == n)
				j = 1000;
		}
		vist[k] = 1;
		for (j = 1; j <= 1000 + m; j++){
			if (!vist[j] && dist[k] + map[k][j] < dist[j])
				dist[j] = dist[k] + map[k][j];
			if (j == n)
				j = 1000;
		}
	}
}

int main()
{
	char from[5], to[5];
	int i, j, dis, len, fid, tid;
	int rid, rmin, rtotal;

	scanf("%d %d %d %d", &n, &m, &k, &d);
	for (i = 1; i < 1011; i++)
		for (j = 1; j < 1011; j++)
			map[i][j] = Inf;

	for (i = 0; i < k; i++){
		scanf("%s %s %d", from, to, &dis);
		if (from[0] == 'G')
			fid = strToint(from + 1) + 1000;
		else
			fid = strToint(from);
		if (to[0] == 'G')
			tid = strToint(to + 1) + 1000;
		else
			tid = strToint(to);
		map[fid][tid] = map[tid][fid] = dis;
	}

	for (i = 1001; i <= 1000 + m; i++){
		for (j = 1; j < 1011; j++){
			vist[j] = 0; 
			dist[j] = Inf;
		}
		Dijstra(i);
		list[i - 1000].isOK = 1;
		list[i - 1000].total = 0;
		list[i - 1000].dmin = Inf;
		for (j = 1; j <= n; j++){
			if (dist[j] <= d)
				list[i - 1000].total += dist[j];
			else
				list[i - 1000].isOK = 0;
			if (dist[j] < list[i - 1000].dmin)
				list[i - 1000].dmin = dist[j];
		}
	}
	rid = -1;
	rmin = -1;
	rtotal = Inf;
	for (i = 1; i <= m; i++){
		if (list[i].isOK){
			if (list[i].dmin > rmin){
				rid = i;
				rmin = list[i].dmin;
				rtotal = list[i].total;
			}
			else if (list[i].dmin == rmin){
				if (list[i].total<rtotal){
					rid = i;
					rtotal = list[i].total;
				}
			}
		}
	}
	if (rid == -1)
		printf("No Solution\n");
	else{
		printf("G%d\n", rid);
		printf("%.1f %.1f\n", rmin*1.0, rtotal*1.0 / n);
	}
	return 0;
}