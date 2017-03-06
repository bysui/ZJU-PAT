#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char id[7];
	int score[4];
	int rank[4];
}Student;

int comp1(const void *a, const void *b)
{
	Student *s1, *s2;
	
	s1 = (Student*)a;
	s2 = (Student*)b;
	return s2->score[0] - s1->score[0];
}

int comp2(const void *a, const void *b)
{
	Student *s1, *s2;

	s1 = (Student*)a;
	s2 = (Student*)b;
	return s2->score[1] - s1->score[1];
}

int comp3(const void *a, const void *b)
{
	Student *s1, *s2;

	s1 = (Student*)a;
	s2 = (Student*)b;
	return s2->score[2] - s1->score[2];
}

int comp4(const void *a, const void *b)
{
	Student *s1, *s2;

	s1 = (Student*)a;
	s2 = (Student*)b;
	return s2->score[3] - s1->score[3];
}

int main()
{
	int i, j, t, n, m, last, cnt, best;
	char id[7];
	char idlist[4][2000][7];
	char out[4] = { 'A', 'C', 'M', 'E' };
	Student list[2000];
	int(*func[4])(const void*, const void*) = {comp1, comp2, comp3, comp4};

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++){
		scanf("%s %d %d %d", list[i].id, &list[i].score[1], &list[i].score[2], &list[i].score[3]);
		list[i].score[0] = (list[i].score[1] + list[i].score[2] + list[i].score[3]) / 3;
	}

	for (i = 0; i < 4; i++){
		qsort(list, n, sizeof(Student), func[i]);
		cnt = last = 0;
		for (j = 0; j < n; j++){
			if (last != list[j].score[i]){
				cnt = j + 1;
				last = list[j].score[i];
			}
			list[j].rank[i] = cnt;
			
		}
	}

	for (i = 0; i < m; i++){
		scanf("%s", id);
		for (j = 0; j < n; j++){
			if (strcmp(list[j].id, id) == 0){
				best = 0;
				for (t = 0; t < 4; t++){
					if (list[j].rank[t] < list[j].rank[best])
						best = t;
				}
				printf("%d %c\n", list[j].rank[best], out[best]);
				break;
			}
		}
		if (j == n)
			printf("N/A\n");
	}
	return 0;
}