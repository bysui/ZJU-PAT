#include <stdio.h>

int a[100000];

int findNotRight(int last, int size)
{
	int i;

	for (i = last; i < size; i++)
		if (a[i] != i)
			break;
	return i;
}

int main()
{
	int i, n, firstPos, tmp, count;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	firstPos = findNotRight(firstPos, n);
	count = 0;
	while (firstPos < n){
		if (a[0] == 0){
			a[0] = a[firstPos];
			a[firstPos] = 0;
			count++;
		}
		while (a[0] != 0){
			tmp = a[0];
			a[0] = a[tmp];
			a[tmp] = tmp;
			count++;
		}
		firstPos = findNotRight(firstPos, n);
	}
	printf("%d\n", count);
	return 0;
}