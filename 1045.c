#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[201][10001];
int favorite[200];
int stripe[10000];
int n, m, l;

int main()
{
	int i, j;
	
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf("%d", &favorite[i]);
	scanf("%d", &l);
	for (i = 0; i < l; i++)
		scanf("%d", &stripe[i]);
	for (i = 1; i <= m; i++){
		for (j = 1; j <= l; j++){
			map[i][j] = max(max(map[i][j - 1], map[i - 1][j]), map[i - 1][j - 1]);
			if (favorite[i - 1] == stripe[j - 1])
				map[i][j]++;
		}
	}
	printf("%d\n", map[m][l]);
	return 0;
}