#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, end, n, count, first, start, tmp;

	scanf("%d", &n);
	end = sqrt(n*1.0);
	count = 0;
	first = n;
	for (i = 2; i <= end; i++){
		start = i;
		tmp = n;
		while (tmp % start == 0){
			tmp /= start;
			start++;
		}
		if (start - i > count){
			count = start - i;
			first = i;
		}
	}

	if (count == 0)
		printf("1\n%d\n", n);
	else{
		printf("%d\n", count);
		printf("%d", first);
		for (i = 1; i < count; i++)
			printf("*%d", first + i);
		printf("\n");
	}
}