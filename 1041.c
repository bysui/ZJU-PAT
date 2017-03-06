#include <stdio.h>

int num[10001];
int rd[100000];

int main()
{
	int i, n;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &rd[i]);
		num[rd[i]]++;
	}
	for (i = 0; i < n; i++){
		if (num[rd[i]] == 1){
			printf("%d\n", rd[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}