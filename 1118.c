#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int bird[10001];

int findRoot(int x)
{
	if (bird[x] == 0)
		return x;
	else
		return bird[x] = findRoot(bird[x]);
}

int main()
{
	int i, j, cnt, bid, mid, bcount;
	int r1, r2, b1, b2;

	scanf("%d", &n);
	mid = -1;
	for (i = 0; i < n; i++){
		scanf("%d", &cnt);
		if (cnt > 0){
			scanf("%d", &bid);
			r1 = findRoot(bid);
			if (bid > mid)
				mid = bid;
		}
		for (j = 1; j < cnt; j++){
			scanf("%d", &bid);
			r2 = findRoot(bid);
			if (r1 != r2)
				bird[r2] = r1;
			if (bid > mid)
				mid = bid;
		}
	}
	bcount = 0;
	for (i = 1; i <= mid; i++){
		if (bird[i] == 0)
			bcount++;
	}
	printf("%d %d\n", bcount, mid);

	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++){
		scanf("%d %d", &b1, &b2);
		r1 = findRoot(b1);
		r2 = findRoot(b2);
		if (r1 == r2)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}