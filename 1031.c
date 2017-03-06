#include <stdio.h>
#include <string.h>

char str[80];

int main()
{
	int i, j, len, n1, n2;

	scanf("%s", str);
	len = strlen(str);
	n1 = (len + 2) / 3;
	n2 = len + 2 - 2 * n1;
	for (i = 0; i < n1 - 1; i++){
		printf("%c", str[i]);
		for (j = 0; j < n2 - 2; j++)
			printf(" ");
		printf("%c\n", str[len - 1 - i]);
	}
	for (i = n1 - 1; i < len + 1 - n1; i++){
		printf("%c", str[i]);
	}
	return 0;
}