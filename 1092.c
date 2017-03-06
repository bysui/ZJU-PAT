#include <stdio.h>

int str[62];

int main()
{
	int i, len1, len2, c1, c2;
	char ch;

	len1 = 0;
	while ((ch = getchar()) != '\n'){
		if (ch >= '0'&&ch <= '9')
			str[ch - '0']++;
		if (ch >= 'a'&&ch <= 'z')
			str[ch - 'a' + 10]++;
		if (ch >= 'A'&&ch <= 'Z')
			str[ch - 'A' + 36]++;
		len1++;
	}
	len2 = 0;
	while ((ch = getchar()) != '\n'){
		if (ch >= '0'&&ch <= '9')
			str[ch - '0']--;
		if (ch >= 'a'&&ch <= 'z')
			str[ch - 'a' + 10]--;
		if (ch >= 'A'&&ch <= 'Z')
			str[ch - 'A' + 36]--;
		len2++;
	}
	c1 = c2 = 0;
	for (i = 0; i < 62; i++){
		if (str[i] < 0)
			c2 -= str[i];
		if (str[i] > 0)
			c1 += str[i];
	}
	if (c2 > 0)
		printf("No %d\n", c2);
	else
		printf("Yes %d\n", c1);
	return 0;
}