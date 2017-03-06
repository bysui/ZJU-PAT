#include <stdio.h>

int coin[1001];

int main()
{
	int i, n, m, v, flag;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++){
		scanf("%d", &v);
		coin[v]++;
	}
	flag = 0;
	for (i = 1; i <= m / 2; i++){
		coin[i]--;
		coin[m - i]--;
		if (coin[i] >= 0 && coin[m - i] >= 0){
			printf("%d %d\n", i, m - i);
			flag = 1;
			break;
		}
	}
	if (!flag)
		printf("No Solution\n");
	return 0;
}