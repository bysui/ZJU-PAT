#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[11];
	char id[11];
	int grade;
	int gender;
}Record;

Record list[1000];

int comp(const void *a, const void *b)
{
	Record *r1, *r2;

	r1 = (Record*)a;
	r2 = (Record*)b;
	if (r1->gender == r2->gender)
		return r2->grade - r1->grade;
	else
		return r1->gender - r2->gender;
}

int main()
{
	int i, n, cnt, flag;
	char ch;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%s %c %s %d", list[i].name, &ch, list[i].id, &list[i].grade);
		if (ch == 'F')
			list[i].gender = 0;
		else
			list[i].gender = 1;
	}
	qsort(list, n, sizeof(Record), comp);
	flag = 0;
	if (list[0].gender != 0){
		printf("Absent\n");
		flag = 1;
	}
	else
		printf("%s %s\n", list[0].name, list[0].id);
	if (list[n - 1].gender != 1){
		printf("Absent\n");
		flag = 1;
	}
	else
		printf("%s %s\n", list[n - 1].name, list[n - 1].id);
	if (flag)
		printf("NA\n");
	else
		printf("%d\n", list[0].grade - list[n - 1].grade);
	

	return 0;
}