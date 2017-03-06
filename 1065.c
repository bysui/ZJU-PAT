#include <stdio.h>

int main()
{
	int i, t;
	long long a, b, sum, c, flag;

	scanf("%d", &t);
	for (i = 1; i <= t; i++){
		scanf("%lld %lld %lld", &a, &b, &c);
		flag = 0;
		sum = a + b;
		if (a > 0 && b > 0 && sum <= 0)
			flag = 1;
		else if (a < 0 && b < 0 && sum >= 0)
			flag = 0;
		else
			flag = sum > c;
		if (flag)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}
	return 0;
}