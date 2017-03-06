#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char num[9];
}Segment;

Segment seg[10000];

int comp(const void *a, const void *b)
{
	Segment *s1, *s2;
	char link1[20], link2[20];

	s1 = (Segment*)a;
	s2 = (Segment*)b;
	strcpy(link1, s1->num);
	strcat(link1, s2->num);
	strcpy(link2, s2->num);
	strcat(link2, s1->num);
	return strcmp(link1, link2);

}

int main()
{
	int i, j, n, len, flag;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", seg[i].num);
	qsort(seg, n, sizeof(Segment), comp);
	flag = 0;
	for (i = 0; i < n; i++){
		if (!flag){
			len = strlen(seg[i].num);
			j = 0;
			while (j < len && seg[i].num[j] == '0')
				j++;
			printf("%s", seg[i].num + j);
			if (j != len)
				flag = 1;
		}
		else
			printf("%s", seg[i].num);
	}
	if (!flag)
		printf("0\n");

	return 0;
}