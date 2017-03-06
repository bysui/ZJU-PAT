#include <stdio.h>
#include <stdlib.h>

int a[100000];

int num[2][4];

int comp(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

void intTodigit(int n)
{
	num[0][0] = n / 1000;
	num[0][1] = n / 100 % 10;
	num[0][2] = n / 10 % 10;
	num[0][3] = n % 10;
	qsort(num[0], 4, sizeof(int), comp);
}

int digitToint(int index)
{
	int i, sum;

	sum = 0;
	for (i = 0; i < 4; i++)
		sum = sum * 10 + num[index][i];
	return sum;
}

void getHoleNumber()
{
	int i, n1, n2, re;
	while (digitToint(0) != 6174){
		for (i = 0; i < 4; i++)
			num[1][i] = num[0][3-i];
		n1 = digitToint(0);
		n2 = digitToint(1);
		re = n1 - n2;
		printf("%04d - %04d = %04d\n", n1, n2, re);
		if (re == 6174)
			break;
		intTodigit(re);
	}
}

int main()
{
	int i, n;
	
	scanf("%d", &n);
	
	intTodigit(n);
	if (num[0][0] == num[0][1] && num[0][0] == num[0][2] && num[0][0] == num[0][3])
		printf("%04d - %04d = %04d\n", digitToint(0), digitToint(0), 0);
	else
		getHoleNumber();

	return 0;
}