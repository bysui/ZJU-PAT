#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<pair<int ,int>> road;
vector<int> cset;

int findRoot(int x)
{
	if (cset[x] == -1)
		return x;
	else
		return cset[x] = findRoot(cset[x]);
}
int main()
{
	int i, j, c1, c2, lost, r1, r2, sets; 

	cin >> n >> m >> k;
	road.resize(m);
	cset.resize(n + 1);
	for (i = 0; i < m; i++){
		cin >> c1 >> c2;
		road[i] = make_pair(c1, c2);
	}
	
	for (i = 0; i < k; i++){
		cin >> lost;
		for (j = 1; j <= n; j++)
			cset[j] = -1;
		for (j = 0; j < m; j++){
			if (road[j].first != lost && road[j].second != lost){
				r1 = findRoot(road[j].first);
				r2 = findRoot(road[j].second);
				if (r1 != r2)
					cset[r1] = r2;
			}
		}
		sets = 0;
		for (j = 1; j <= n; j++){
			if (cset[j] == -1)
				sets++;
		}
		printf("%d\n", sets - 2);
	}
	return 0;
}