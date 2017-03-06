#include <stdio.h>
#include <string.h>

int charToint(char digit)
{
	if (digit <= '9')
		return digit - '0';
	else
		return digit - 'a' + 10;
}

long long strToint(const char *num, long long radix)
{
	long long result;
	int i, len;

	len = strlen(num);
	result = 0;
	for (i = 0; i < len; i++){
		result = result * radix + charToint(num[i]);
		if (result < 0)
			return -1;
	}
	return result;
}

int findMinRadix(const char *num)
{
	int i, len;
	char ch;

	len = strlen(num);
	ch = '1';
	for (i = 0; i < len; i++){
		if (num[i] > ch)
			ch = num[i];
	}
	return charToint(ch) + 1;
}

int main()
{
	char n[2][11];
	int i, tag, flag;
	long long num1, num2, radix, min, mid, max;

	scanf("%s %s %d %lld", n[0], n[1], &tag, &radix);
	num1 = strToint(n[tag/2], radix);

	min = findMinRadix(n[tag%2]);
	max = num1 + 1;
	flag = 0;
	while (min <= max){
		mid = (min + max) / 2;
		num2 = strToint(n[tag%2], mid);
		if (num2 == -1 || num2 > num1)
			max = mid - 1;
		else if (num2 < num1)
			min = mid + 1;
		else{
			flag = 1;
			break;
		}
	}

	if (flag)
		printf("%lld\n", mid);
	else
		printf("Impossible\n");		
	return 0;
}