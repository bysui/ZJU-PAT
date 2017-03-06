#include <stdio.h>

int main()
{
	int i, carry;
	int a[3][3];
	int radix[] = { 29, 17 };

	for (i = 0; i < 2; i++)
		scanf("%d.%d.%d", &a[i][2], &a[i][1], &a[i][0]);
	carry = 0;
	for (i = 0; i < 2; i++){
		a[2][i] = (a[0][i] + a[1][i] + carry) % radix[i];
		carry = (a[0][i] + a[1][i] + carry) / radix[i];
	}
	a[2][i] = a[0][i] + a[1][i] + carry;
	printf("%d.%d.%d\n", a[2][2], a[2][1], a[2][0]);
	return 0;
}