#include <stdio.h>

int d[100001];

int main()
{
	int i, j, n, m, dist, total, s1, s2, t1, t2;

	scanf("%d", &n);
	total = 0;
	for (i = 1; i <= n; i++){
		scanf("%d", &dist);
		d[i] = total;
		total += dist;
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++){
		scanf("%d %d", &s1, &s2);
		if (s1 < s2)
			t1 = d[s2] - d[s1];
		else
			t1 = d[s1] - d[s2];
		t2 = total - t1;
		if (t1 < t2)
			printf("%d\n", t1);
		else
			printf("%d\n", t2);
	}
}