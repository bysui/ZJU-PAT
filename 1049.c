#include<stdio.h>

int main()
{
	int n, count, factor;
	int higher, lower, cur;

	scanf("%d", &n);
	
	count = 0;
	factor = 1;
	while (n / factor != 0){
		higher = n / (factor * 10);
		lower = n - (n / factor) * factor;
		cur = (n / factor) % 10;
		switch (cur){
		case 0:
			count += higher * factor;
			break;
		case 1:
			count += higher * factor + lower + 1;
			break;
		default:
			count += higher * factor + factor;
		}
		factor = factor * 10;
	}
	printf("%d\n", count);
	return 0;
}
