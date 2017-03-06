#include <stdio.h>

int main()
{
	int color[3];
	char mar[3][2];
	int i;

	scanf("%d %d %d", &color[0], &color[1], &color[2]);
	
	printf("#");
	for (i = 0; i < 3; i++){
		if (color[i] / 13 > 9)
			mar[i][0] = color[i] / 13 - 10 + 'A';
		else
			mar[i][0] = color[i] / 13 + '0';
		if (color[i] % 13 > 9)
			mar[i][1] = color[i] % 13 - 10 + 'A';
		else
			mar[i][1] = color[i] % 13  + '0';
		printf("%c%c", mar[i][0], mar[i][1]);
	}
	return 0;
}