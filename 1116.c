#include <stdio.h>
#include <math.h>

int rank[10000];
int check[10000];

int isPrime(int x)
{
	int i, half;

	half = sqrt(x * 1.0);
	for (i = 2; i <= half; i++){
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int cal(int x)
{
	if (x == 1)
		return 0;
	if (isPrime(x))
		return 1;
	else
		return 2;
}

int main()
{
	int i, n, k, id;
	const char* award[] = {"Mystery Award", "Minion", "Chocolate"};
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &id);
		rank[id] = i;
	}
	scanf("%d", &k);
	for (i = 1; i <= k; i++){
		scanf("%d", &id);
		printf("%04d: ", id);
		if (rank[id]){
			if (!check[id]){
				check[id] = 1;
				printf("%s\n", award[cal(rank[id])]);
			}
			else
				printf("Checked\n");
		}
		else
			printf("Are you kidding?\n");
	}
	return 0;
}