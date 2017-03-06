#include <stdio.h>
#include <stdlib.h>

typedef struct{
	double amount;
	double price;
}MoonCake;

MoonCake list[1000];

int comp(const void *a, const void *b)
{
	MoonCake *m1, *m2;

	m1 = (MoonCake*)a;
	m2 = (MoonCake*)b;

	return m1->price / m1->amount < m2->price / m2->amount;;
}


int main()
{
	int i, n, need, count;
	double price;
	
	scanf("%d %d", &n, &need);
	for (i = 0; i < n; i++)
		scanf("%lf", &list[i].amount);
	for (i = 0; i < n; i++)
		scanf("%lf", &list[i].price);

	qsort(list, n, sizeof(MoonCake), comp);
	i = 0;
	price = 0;
	while (i < n && need){
		if (need - list[i].amount <= 0){
			price += need * list[i].price / list[i].amount;
			need = 0;
		}
		else{
			price += list[i].price;
			need -= list[i].amount;
			i++;
		}
	}
	printf("%.2f\n", price);
	return 0;
}