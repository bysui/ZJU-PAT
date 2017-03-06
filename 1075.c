#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int id, total, isRank, full;
	int score[6];
}Student;

Student list[10001];
int score[6];

int comp(const void *a, const void *b)
{
	Student *s1, *s2;

	s1 = (Student*)a;
	s2 = (Student*)b;

	if (s1->isRank == s2->isRank){
		if (s1->total == s2->total){
			if (s1->full == s2->full)
				return s1->id - s2->id;
			else
				return s1->full < s2->full;
		}
		else
			return s1->total < s2->total;
	}
	else
		return s1->isRank < s2->isRank;
}

int main()
{
	int i, j, n, k, m;
	int id, pid, pscore;
	int last, rank;

	scanf("%d %d %d", &n, &k, &m);
	for (i = 1; i <= k; i++)
		scanf("%d", &score[i]);
	for (i = 1; i <= n; i++){
		list[i].id = i;
		list[i].isRank = 0;
		list[i].total = 0;
		list[i].full = 0;
		for (j = 1; j <= k; j++)
			list[i].score[j] = -1;
	}
	for (i = 0; i < m; i++){
		scanf("%d %d %d", &id, &pid, &pscore);
		if (pscore != -1){
			list[id].isRank = 1;
			if (pscore > list[id].score[pid]){
				list[id].score[pid] = pscore;
				if (pscore == score[pid])
					list[id].full++;
			}
		}
		else{
			if (list[id].score[pid] == -1)
				list[id].score[pid] = 0;
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= k; j++)
			if (list[i].score[j] >= 0)
				list[i].total += list[i].score[j];
	}

	qsort(list + 1, n, sizeof(Student), comp);
	last = list[1].total;
	rank = 1;
	for (i = 1; i <= n; i++){
		if (list[i].isRank){
			if (list[i].total != last){
				rank = i;
				last = list[i].total;
			}
			printf("%d %05d %d", rank, list[i].id, list[i].total);
			for (j = 1; j <= k; j++)
				if (list[i].score[j] >= 0)
					printf(" %d", list[i].score[j]);
				else
					printf(" -");
			printf("\n");
		}
		else
			break;
	}
	return 0;
}