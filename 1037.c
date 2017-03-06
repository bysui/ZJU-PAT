#include <stdio.h>
#include <stdlib.h>

int s[2][100000];

int comp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int i, j, sum;
	int n[2];

	for (i = 0; i < 2; i++){
		scanf("%d", &n[i]);
		for (j = 0; j < n[i]; j++){
			scanf("%d", &s[i][j]);
		}
	}
	qsort(s[0], n[0], sizeof(int), comp);
	qsort(s[1], n[1], sizeof(int), comp);
	i = j = 0;
	sum = 0;
	while (i < n[0] && j < n[1] && s[0][i] < 0 && s[1][j] < 0){
		sum += s[0][i] * s[1][j];
		i++; 
		j++;
	}
	i = n[0] - 1;
	j = n[1] - 1;
	while (i >= 0 && j >= 0 && s[0][i] > 0 && s[1][j] > 0){
		sum += s[0][i] * s[1][j];
		i--;
		j--;
	}
	printf("%d\n", sum);
	return 0;
}