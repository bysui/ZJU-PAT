#include <stdio.h>
#include <stdlib.h>

int seq[100000];

int comp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int i, n, m1, m2, len;
	long long p;

	scanf("%d %lld", &n, &p);
	for (i = 0; i < n; i++)
		scanf("%d", &seq[i]);
	
	qsort(seq, n, sizeof(int), comp);
	m1 = 0;
	m2 = 0;
	len = 0;
	while (1){
		while (m2 < n && seq[m1] * p >= seq[m2])
			m2++;
		if (m2 - m1 > len)
			len = m2 - m1;
		if (m2 == n)
			break;
		while (m1 <= m2&&seq[m1] * p < seq[m2])
			m1++;
	}
	printf("%d\n", len);
	return 0;
}