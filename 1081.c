#include <stdio.h>

typedef struct{
	long long a, b;
}Rational;

Rational num[100];

long long factor(long long a, long long b)
{
	long long m, n, c;

	if (a < 0)
		a = -a;
	m = a >= b ? a : b;
	n = a < b ? a : b;
	while (n){
		c = m % n;
		m = n;
		n = c;
	}
	return m;
}

void add(Rational *sum, Rational* n)
{
	long long nume, den, fact;

	den = sum->b * n->b;
	nume = sum->a * n->b + n->a*sum->b;
	fact = factor(nume, den);
	sum->a = nume / fact;
	sum->b = den / fact;
}

int main()
{
	int i, n;
	long long digit;
	Rational sum;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%lld/%lld", &num[i].a, &num[i].b);

	sum.a = 0;
	sum.b = 1;
	for (i = 0; i < n; i++)
		add(&sum, &num[i]);
	if (sum.a == 0)
		printf("0\n");
	else{
		if (sum.a < 0){
			printf("-");
			sum.a = -sum.a;
		}
		digit = sum.a / sum.b;
		sum.a = sum.a % sum.b;
		if (digit != 0 && sum.a == 0)
			printf("%lld\n", digit);
		else if (digit != 0 && sum.a != 0)
			printf("%lld %lld/%lld\n", digit, sum.a, sum.b);
		else if (digit == 0 && sum.a != 0)
			printf("%lld/%lld\n", sum.a, sum.b);
	}
	return 0;
}