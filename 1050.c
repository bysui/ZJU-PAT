#include <stdio.h>
#include <string.h>

char s1[10001], s2[10001];

int main()
{
	int i, len;

	gets(s1);
	gets(s2);

	len = strlen(s1);
	for (i = 0; i < len; i++){
		if (strchr(s2, s1[i]) == NULL)
			putchar(s1[i]);
	}
	return 0;
}