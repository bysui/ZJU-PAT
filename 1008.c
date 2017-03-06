#include <stdio.h>

int main()
{
	int i, n, now, next, time;

	now = time = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &next);
		if (now < next)
			time += (next - now) * 6 + 5;
		else
			time += (now - next) * 4 + 5;
		now = next;
	}

	printf("%d\n", time);
	return 0;
}