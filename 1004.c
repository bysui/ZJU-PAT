#include <stdio.h>
#include <memory.h>

int tree[100][100];
int leaf[100] = {0};

void dfs(int node, int level)
{
	int i;

	if (tree[node][0] == 0){
		leaf[level]++;
		return;
	}
	for (i = 0; tree[node][i] != 0; i++)
		dfs(tree[node][i], level + 1);
}

int main()
{
	int i, j, n, m, cnt, sum;
	int id, k;

	memset(tree, 0, sizeof(tree));
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++){
		scanf("%d %d", &id, &k);
		for (j = 0; j < k; j++)
			scanf("%d", &tree[id][j]);
	}
	dfs(1, 0);

	printf("%d", leaf[0]);
	cnt = leaf[0];
	sum = n - m;
	for (i = 1; cnt < sum; i++){
		printf(" %d", leaf[i]);
		cnt += leaf[i];
	}
	return 0;
}