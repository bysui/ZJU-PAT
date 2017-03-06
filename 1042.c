#include <stdio.h>

int card[54];
int order[54];

int main()
{
	int i, j, n;

	scanf("%d", &n);
	for (i = 0; i < 54; i++){
		card[i] = i;
		scanf("%d", &order[i]);
	}
	for (i = 0; i < n; i++){
		int back[54];
		for (j = 0; j < 54; j++)
			back[j] = card[j];
		for (j = 0; j < 54; j++)
			card[order[j] - 1] = back[j];
	}
	for (i = 0; i < 54; i++){
		if (card[i] >= 0 && card[i] < 13)
			printf("S%d", card[i] % 13 + 1);
		if (card[i] >= 13 && card[i] < 26)
			printf("H%d", card[i] % 13 + 1);
		if (card[i] >= 26 && card[i] < 39)
			printf("C%d", card[i] % 13 + 1);
		if (card[i] >= 39 && card[i] < 52)
			printf("D%d", card[i] % 13 + 1);
		if (card[i] >= 52 && card[i] < 54)
			printf("J%d", card[i] - 51);
		if (i < 53)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}