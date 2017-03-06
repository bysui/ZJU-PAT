#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[10];
	int age;
	int net;
}Person;

Person list[100000];

int comp(const void *a, const void *b)
{
	Person *p1, *p2;

	p1 = (Person*)a;
	p2 = (Person*)b;
	if (p1->net == p2->net){
		if (p1->age == p2->age)
			return strcmp(p1->name, p2->name);
		else
			return p1->age - p2->age;
	}
	else
		return p2->net - p1->net;
}

int main()
{
	int i, j, n, m;
	int k, cnt, a1, a2;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s %d %d", list[i].name, &list[i].age, &list[i].net);
	qsort(list, n, sizeof(Person), comp);

	for (i = 1; i <= m; i++){
		scanf("%d %d %d", &k, &a1, &a2);
		printf("Case #%d:\n", i);
		cnt = 0;
		for (j = 0; j < n; j++){
			if (list[j].age >= a1&&list[j].age <= a2){
				printf("%s %d %d\n", list[j].name, list[j].age, list[j].net);
				cnt++;
				if (cnt == k)
					break;
			}
		}
		if (cnt == 0)
			printf("None\n");
	}
	return 0;
}

