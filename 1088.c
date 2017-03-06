#include <stdio.h>

typedef struct{
	long long a, b;
}Rational;

long long gcd(long long a, long long b)
{
	long long m, n, c;

	if (a < 0)
		a = -a;
	n = a >= b ? a : b;
	m = a < b ? a : b;
	while (m){
		c = n % m;
		n = m;
		m = c;
	}
	return n;
}

void simply(Rational *r)
{
	long long fact;

	fact = gcd(r->a, r->b);
	r->a /= fact;
	r->b /= fact;
}

void print(Rational r)
{
	long long p;
	int flag;

	if (r.a == 0){
		printf("0");
		return;
	}
	if (r.b == 0){
		printf("Inf");
		return;
	}
	flag = 0;
	if (r.a < 0){
		printf("(-");
		r.a = -r.a;
		flag = 1;
	}
	p = r.a / r.b;
	r.a = r.a % r.b;
	if (p != 0 && r.a != 0)
		printf("%lld %lld/%lld", p, r.a, r.b);
	if (p != 0 && r.a == 0)
		printf("%lld", p);
	if (p == 0 && r.a != 0)
		printf("%lld/%lld", r.a, r.b);
	if (flag)
		printf(")");
}

int main()
{
	Rational r1, r2, r3;
	int i;

	scanf("%lld/%lld %lld/%lld", &r1.a, &r1.b, &r2.a, &r2.b);
	simply(&r1);
	simply(&r2);
	for (i = 0; i < 4; i++){
		print(r1);
		switch (i){
			case 0:
				r3.a = r1.a * r2.b + r2.a * r1.b;
				r3.b = r1.b * r2.b;
				printf(" + ");
				break;
			case 1:
				r3.a = r1.a * r2.b - r2.a * r1.b;
				r3.b = r1.b * r2.b;
				printf(" - ");
				break;
			case 2:
				r3.a = r1.a * r2.a;
				r3.b = r1.b * r2.b;
				printf(" * ");
				break;
			case 3:
				r3.a = r1.a * r2.b;
				r3.b = r1.b * r2.a;
				if (r3.b < 0){
					r3.b = -r3.b;
					r3.a = -r3.a;
				}
				printf(" / ");
				break;
		}
		print(r2);
		printf(" = ");
		simply(&r3);
		print(r3);
		printf("\n");
	}
	return 0;
}