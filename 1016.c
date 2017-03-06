#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[21];
	int day, hour, minute;
	int time;
	int onOroff;
}Record;

int comp(const void *a, const void *b)
{
	Record *r1 = (Record *)a;
	Record *r2 = (Record *)b;

	int c1 = strcmp(r1->name, r2->name);
	if (c1 != 0)
		return c1;
	else
		return r1->time - r2->time;

}

int main()
{
	Record rd[1000];
	int rate[24];
	char state[10], name[21];
	int i, j, n, month, flag1, flag2, start, end, dcost, cost1, cost2, total, time;

	dcost = 0;
	for (i = 0; i < 24; i++){
		scanf("%d", &rate[i]);
		dcost += 60 * rate[i];
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%s %d:%d:%d:%d %s", rd[i].name, &month, &rd[i].day, &rd[i].hour, &rd[i].minute, state);
		rd[i].time = rd[i].day * 24 * 60 + rd[i].hour * 60 + rd[i].minute;
		if (state[1] == 'n')
			rd[i].onOroff = 1;
		else
			rd[i].onOroff = 0;
	}
	qsort(rd, n, sizeof(Record), comp);

	for (i = 0; i < n; i++){
		strcpy(name, rd[i].name);
		flag1 = flag2 = 0;
		total = 0;
		while (!strcmp(name, rd[i].name)){
			if (rd[i].onOroff == 1){
				flag2 = 1;
				start = i;
			}
			if (rd[i].onOroff == 0 && flag2 == 1){
				end = i;
				flag2 = 0;
				cost1 = cost2 = 0;
				if (!flag1){
					flag1 = 1;
					printf("%s %02d\n", name, month);
				}
				printf("%02d:%02d:%02d %02d:%02d:%02d", rd[start].day, rd[start].hour, rd[start].minute, rd[end].day, rd[end].hour, rd[end].minute);
				for (j = 0; j < rd[start].hour; j++)
					cost1 += 60 * rate[j];
				cost1 += rate[rd[start].hour] * rd[start].minute;
				for (j = 0; j < rd[end].hour; j++)
					cost2 += 60 * rate[j];
				cost2 += (rd[end].day - rd[start].day) * dcost + rate[rd[end].hour] * rd[end].minute;
				printf(" %d $%.2f\n", rd[end].time - rd[start].time, (cost2 - cost1) / 100.0);
				total += cost2 - cost1;
			}
			i++;
		}
		i--;
		if (flag1)
			printf("Total amount: $%.2f\n", total / 100.0);
	}
	return 0;
}