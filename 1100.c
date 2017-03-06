#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* digit[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };


void change1(char str[])
{
	int num, n1, n2;
	
	num = atoi(str);
	n1 = num % 13;
	n2 = num / 13;
	if (n2 > 0){
		printf("%s", digit[12 + n2]);
		if (n1 > 0){
			printf(" %s\n", digit[n1]);
		}
		else
			printf("\n");
	}
	else
		printf("%s\n", digit[n1]);
}

void change2(char str[])
{

	int i, n1, n2;
	char *num[2];

	num[0] = strtok(str, " ");
	num[1] = strtok(NULL, " ");
	if (num[1] == NULL){
		for (i = 0; i < 25; i++){
			if (strcmp(num[0], digit[i]) == 0)
				break;
		}
		if (i > 12)
			n1 = (i - 12) * 13;
		else
			n1 = i;
		printf("%d\n", n1);
	}
	else{
		for (i = 0; i < 13; i++){
			if (strcmp(num[1], digit[i]) == 0)
				break;
		}
		n1 = i;
		for (i = 13; i < 25; i++){
			if (strcmp(num[0], digit[i]) == 0)
				break;
		}
		n2 = i - 12;
		printf("%d\n", n2 * 13 + n1);
	}
}

int main()
{
	int i, n;
	char str[100][10];

	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		gets(str[i]);
	for (i = 0; i < n; i++){
		if (str[i][0] >= '0' && str[i][0] <= '9')
			change1(str[i]);
		else
			change2(str[i]);
	}
	return 0;
}