#include <stdio.h>

const char* number[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
int flag = 0;

void printsum(int sum)
{
	int n = 0;
	if (sum != 0){
		flag++;
		n = flag;
		printsum(sum / 10);
		printf("%s", number[sum % 10]);
		if (n > 1)
			putchar(' ');
	}
}

int main()
{
	char ch;
	int sum;

	sum = 0;
	while ((ch = getchar()) != '\n'){
		sum += ch - '0';
	}

	if (sum == 0)
		printf("zero");
	else
		printsum(sum);
	return 0;
}