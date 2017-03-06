#include <iostream>
#include <algorithm>
using namespace std;

int node[100001][2];
int list[100001];

int main()
{
	int i, j, start, n, k;
	int id, data, next, ptr;

	cin >> start >> n >> k;
	for (i = 0; i < n; i++){
		cin >> id >> data >> next;
		node[id][0] = data;
		node[id][1] = next;
	}
	ptr = start;
	i = 0;
	while (ptr != -1){
		list[i++] = ptr;
		ptr = node[ptr][1];
	}
	j = 0;
	while (j + k <= i){
		reverse(list + j, list + j + k);
		j += k;
	}
	for (j = 0; j < i - 1; j++)
		printf("%05d %d %05d\n", list[j], node[list[j]][0], list[j + 1]);
	printf("%05d %d -1\n", list[j], node[list[j]][0]);
	return 0;
}
