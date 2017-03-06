#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n;
vector<vector<int>> hobby(1001);
vector<int> root, pcount, res;

int findRoot(int x)
{
	if (root[x] == -1)
		return x;
	else
		return root[x] = findRoot(root[x]);
}

int main()
{
	int i, j, cnt, hid, first;
	int r1, r2;

	scanf("%d", &n);
	root.assign(n, -1);
	pcount.assign(n, 1);
	for (i = 0; i < n; i++){
		scanf("%d:", &cnt);
		for (j = 0; j < cnt; j++){
			scanf("%d", &hid);
			hobby[hid].push_back(i);
		}
	}
	for (i = 1; i <= 1000; i++){
		if (hobby[i].size() == 0)
			continue;
		first = hobby[i][0];
		r1 = findRoot(first);
		for (j = 1; j < hobby[i].size(); j++){
			r2 = findRoot(hobby[i][j]);
			if (r1 != r2){
				root[r2] = r1;
				pcount[r1] += pcount[r2];
			}
		}
	}
	for (i = 0; i < n; i++){
		if (root[i] == -1)
			res.push_back(pcount[i]);
	}
	sort(res.begin(), res.end(), greater<int>());
	printf("%d\n", res.size());

	for (i = 0; i < res.size() - 1; i++)
		printf("%d ", res[i]);
	printf("%d\n", res[i]);
	return 0;
}