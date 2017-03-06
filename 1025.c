#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char id[14];
	int location;
	int score;
}Record;

int comp(const void *a, const void *b)
{
	Record *r1, *r2;

	r1 = (Record*)a;
	r2 = (Record*)b;
	if (r1->score == r2->score)
		return strcmp(r1->id, r2->id);
	else
		return r2->score - r1->score;
}


int main()
{
	Record rd[30000];
	int rank[300], last[300], repeat[300];
	int i, j, n, k, tlast, trank, loc, total;
	char id[14];

	scanf("%d", &n);
	total = 0;
	for (i = 1; i <= n; i++){
		scanf("%d", &k);
		for (j = 0; j < k; j++){
			scanf("%s %d", rd[total + j].id, &rd[total + j].score);
			rd[total + j].location = i;
		}
		total += k;
	}

	qsort(rd, total, sizeof(Record), comp);

	printf("%d\n", total);
	tlast = -1;
	trank = 0;
	memset(rank, 0, sizeof(rank));
	memset(last, -1, sizeof(last));
	memset(repeat, 0, sizeof(repeat));
	for (i = 0; i < total; i++){
		if (rd[i].score != tlast){
			trank = i + 1;
			tlast = rd[i].score;
		}
		loc = rd[i].location;
		if (rd[i].score != last[loc]){
			last[loc] = rd[i].score;
			rank[loc] = rank[loc] + repeat[loc] + 1;
			repeat[loc] = 0;
		}
		else
			repeat[loc]++;
		printf("%s %d %d %d\n", rd[i].id, trank, rd[i].location, rank[loc]);
	}
	return 0;
}