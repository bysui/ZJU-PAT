#include <stdio.h>
#include <memory.h>

int main()
{
	double a[1001], an;
	int i, j, k, n, count;

	memset(a, 0, sizeof(a));
	for (i = 0; i < 2; i++){
		scanf("%d", &k);
		for (j = 0; j < k; j++){
			scanf("%d%lf", &n, &an);
			a[n] += an;
		}
	}

	count = 0;
	for (i = 0; i < 1001; i++){
		if (a[i] != 0)
			count++;
	}
	printf("%d", count);
	for (i = 1000; i >= 0; i--){
		if (a[i] != 0)
			printf(" %d %.1f", i, a[i]);
	}
	printf("\n");

	return 0;
}
