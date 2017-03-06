#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isPrime(int n)
{
	int i, flag;
	int top;

	if (n < 2)
		return 0;

	flag = 1;
	top = sqrt(n*1.0);
	for (i = 2; i <= top; i++){
		if (n%i == 0){
			flag = 0;
			break;
		}
	}
	return flag;
}

int decToRev(int n, int radix)
{
	int num[15];
	int i, len, sum;

	i = 0;
	while (n){
		num[i] = n % radix;
		n = n / radix;
		i++;
	}
	len = i;
	sum = 0;
	for (i = 0; i < len; i++){
		sum = sum*radix + num[i];
	}

	return sum;
}

int main()
{
	int n, radix, rev;

	scanf("%d", &n);
	while (n >= 0){
		scanf("%d", &radix);
		if (isPrime(n)){
			rev = decToRev(n, radix);
			if (isPrime(rev))
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("No\n");
		scanf("%d", &n);
	}
	return 0;
}