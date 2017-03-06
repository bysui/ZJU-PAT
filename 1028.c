#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char name[10];
	int grade;
}Record;

Record rd[100000];

int comp1(const void *a, const void*b)
{
	Record *r1, *r2;

	r1 = (Record*)a;
	r2 = (Record*)b;
	return r1->id - r2->id;
}

int comp2(const void *a, const void*b)
{
	Record *r1, *r2;

	r1 = (Record*)a;
	r2 = (Record*)b;
	if (!strcmp(r1->name, r2->name))
		return r1->id - r2->id;
	else
		return strcmp(r1->name, r2->name);
}

int comp3(const void *a, const void*b)
{
	Record *r1, *r2;

	r1 = (Record*)a;
	r2 = (Record*)b;
	if (r1->grade == r2->grade)
		return r1->id - r2->id;
	else
		return r1->grade - r2->grade;
}

int main()
{
	
	int(*func[])(const void*, const void*) = {comp1, comp2, comp3};
	int i, n, c;

	scanf("%d%d", &n, &c);
	for (i = 0; i < n; i++){
		scanf("%d %s %d", &rd[i].id, rd[i].name, &rd[i].grade);
	}

	qsort(rd, n, sizeof(Record), func[c - 1]);
	for (i = 0; i < n; i++)
		printf("%06d %s %d\n", rd[i].id, rd[i].name, rd[i].grade);

	return 0;
}