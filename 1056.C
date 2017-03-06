#include <cstdio>
#include <vector>
using namespace std;

int weight[1000];
int trank[1000];

int main()
{
	int i, j, n, m, id, size, gnum;
	int max, maxid;
	vector<int> order, tmp;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &weight[i]);
	for (i = 0; i < n; i++){
		scanf("%d", &id);
		order.push_back(id);
	}
	while (order.size() > 1){
		size = order.size();
		gnum = size / m;
		if (size % m != 0)
			gnum++;
		tmp.clear();
		for (i = 0; i < gnum; i++){
			max = maxid = -1;
			for (j = i * m; j < i * m + m&&j < size; j++){
				trank[order[j]] = gnum + 1;
				if (weight[order[j]] > max){
					maxid = order[j];
					max = weight[maxid];
				}
			}
			tmp.push_back(maxid);
		}
		order = tmp;
	}
	trank[order[0]] = 1;
	printf("%d", trank[0]);
	for (i = 1; i < n; i++)
		printf(" %d", trank[i]);
}