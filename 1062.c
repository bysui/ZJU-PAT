#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char id[9];
	int talent, virtue;
	int kind;
}Record;

Record list[100000];

int comp(const void *a, const void *b)
{
	Record *r1, *r2;

	r1 = (Record*)a;
	r2 = (Record*)b;
	if (r1->kind == r2->kind){
		if (r1->talent + r1->virtue == r2->talent + r2->virtue){
			if (r1->virtue == r2->virtue)
				return strcmp(r1->id, r2->id);
			else
				return r2->virtue - r1->virtue;
		}
		else
			return (r2->talent + r2->virtue) - (r1->talent + r1->virtue);
	}
	else
		return r1->kind - r2->kind;
}

int main()
{
	int i, total, n, low, high, t, v;
	char id[9];

	scanf("%d %d %d", &n, &low, &high);
	total = 0;
	for (i = 0; i < n; i++){
		scanf("%s %d %d", id, &v, &t);
		if (v >= low && t >= low){
			strcpy(list[total].id, id);
			list[total].virtue = v;
			list[total].talent = t;
			if (v >= high && t >= high)
				list[total].kind = 1;
			else if (v >= high && t < high)
				list[total].kind = 2;
			else if (v < high && t < high && v >= t)
				list[total].kind = 3;
			else
				list[total].kind = 4;
			total++;
		}
	}

	qsort(list, total, sizeof(Record), comp);
	printf("%d\n", total);
	for (i = 0; i < total; i++)
		printf("%s %d %d\n", list[i].id, list[i].virtue, list[i].talent);

	return 0;
}