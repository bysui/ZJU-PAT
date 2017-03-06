#include <stdio.h>
#include <string.h>
#include <memory.h>

int main()
{
	char num1[22], num2[22];
	int digit[10];
	int i, len, con, n, flag;

	memset(digit, 0, sizeof(digit));
	scanf("%s", num1);
	len = strlen(num1);
	for (i = 0; i < len; i++)
		digit[num1[i] - '0']++;
	con = 0;
	for (i = len - 1; i >= 0; i--){
		n = (num1[i] - '0') * 2 + con;
		if (n > 9){
			n = n - 10;
			con = 1;
		}
		else
			con = 0;
		digit[n]--;
		num2[i] = n + '0';
	}
	num2[len] = '\0';
	if (con)
		digit[1]--;
	flag = 0;
	for (i = 0; i < 10; i++){
		if (digit[i] != 0){
			flag = 1;
			break;
		}
	}
	if (!flag)
		printf("Yes\n");
	else
		printf("No\n");
	if (con)
		printf("1");
	printf("%s\n", num2);
}