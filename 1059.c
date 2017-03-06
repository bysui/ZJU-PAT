#include <stdio.h>
#include <math.h>

int isPrime(long n)
{
	int flag;
	long i, end;

	flag = 1;
	end = sqrt(n * 1.0);
	for (i = 2; i <= end; i++){
		if (n%i == 0){
			flag = 0;
			break;
		}
	}
	return flag;
}

int main()
{
	long i, n, tmp, cnt;
	
	scanf("%ld", &n);
	if (n == 1){
		printf("1=1\n");
		return 0;
	}
	tmp = n;
	printf("%d=", n);
	for (i = 2; i <= n; i++){
		cnt = 0;
		if (isPrime(i)&&tmp%i==0){
			while (tmp%i == 0){
				cnt++;
				tmp /= i;
			}
			if (cnt > 1)
				printf("%d^%d", i, cnt);
			else
				printf("%d", i);
			if (tmp != 1)
				printf("*");
			else
				break;
		}
	}
	return 0;
}