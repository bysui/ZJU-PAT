#include <stdio.h>



int main()
{
	int num[33];
	int i, j, m, n, b, flag;

	scanf("%d%d", &n, &b);
	m = n;
	i = 0;
	if (m == 0){
		printf("Yes\n0");
		return 0;
	}
	while (m){
		num[i] = m % b;
		m = m / b;
		i++;
	}

	flag = 0; 
	for (j = 0; j < i / 2; j++){
		if (num[j] != num[i - j - 1]){
			flag = 1;
			break;
		}
	}
	if (!flag)
		printf("Yes\n");
	else
		printf("No\n");
	printf("%d", num[i-1]);
	for (j = i - 2; j >= 0; j--)
		printf(" %d", num[j]);
	return 0;
}