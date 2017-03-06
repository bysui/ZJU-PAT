#include <stdio.h>
#include <stdlib.h>

int a[1000];
int tree[1000];
int index, n;

void inOrder(int root)
{
	if (root <= n){
		inOrder(root * 2);
		tree[root] = a[index++];
		inOrder(root * 2 + 1);
	}
}

int comp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	qsort(a, n, sizeof(int), comp);
	inOrder(1);

	printf("%d", tree[1]);
	for (i = 2; i <= n; i++)
		printf(" %d", tree[i]);
	
	return 0;
}