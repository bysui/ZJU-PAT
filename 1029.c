#include <stdio.h>

long int s[2][1000000];

int main()
{
	int n[2];
	int i, j, last, t, mid, index;


	for (i = 0; i < 2; i++){
		scanf("%ld", &n[i]);
		for (j = 0; j < n[i]; j++)
			scanf("%ld", &s[i][j]);
	}
	mid = (n[0] + n[1] - 1)/2;
	i = j = 0;
	index = 0;
	while (i < n[0] && j < n[1]){
		if (s[0][i] <= s[1][j]){
			if (index == mid){
				printf("%ld\n", s[0][i]);
				break;
			}
			index++;
			i++;
		}
		else{
			if (index == mid){
				printf("%ld\n", s[1][j]);
				break;
			}
			index++;
			j++;
		}
	}
	if (i == n[0])
		printf("%ld\n", s[1][mid + j - index]);
	else if (j == n[1])
		printf("%ld\n", s[0][mid + i - index]);
	return 0;
}