#include <stdio.h>
#include <memory.h>

int main()
{
	double a[2][1001], product[2001];
	int i, j, k, n, count;
	double an;

	memset(a, 0, sizeof(a));
	memset(product, 0, sizeof(product));

	for (i = 0; i < 2; i++){
		scanf("%d", &k);
		for (j = 0; j < k; j++){
			scanf("%d%lf", &n, &an);
			a[i][n] = an;
		}
	}
	for (i = 0; i < 1001; i++){
		for (j = 0; j < 1001; j++){
			product[i + j] += a[0][i] * a[1][j];
		}
	}
	count = 0;
	for (i = 0; i < 2001; i++){
		if (product[i] != 0)
			count++;
	}
	printf("%d", count);
	for (i = 2000; i >= 0; i--){
		if (product[i] != 0)
			printf(" %d %.1f", i, product[i]);
	}

	return 0;
}