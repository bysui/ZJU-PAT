#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int amount[100001];
int rlevel[100001];
int n;
double p, r;
vector<vector<int>> chain;

void dfs(int root)
{
	int i, size;

	size = chain[root].size();
	for (i = 0; i < size; i++){
		if (rlevel[chain[root][i]] == 0){
			rlevel[chain[root][i]] = rlevel[root] + 1;
			dfs(chain[root][i]);
		}
	}
}

int main()
{
	int i, j, cnt, pp, id;
	double sum;
	
	scanf("%d %lf %lf", &n, &p, &r);
	r = 1 + 0.01 * r;
	chain.resize(n);
	for (i = 0; i < n; i++){
		scanf("%d", &cnt);
		if (cnt == 0){
			scanf("%d", &pp);
			amount[i] = pp;
		}
		else{
			for (j = 0; j < cnt; j++){
				scanf("%d", &id);
				chain[i].push_back(id);
			}
		}
	}
	rlevel[0] = 1;
	dfs(0);
	sum = 0;
	for (i = 0; i < n; i++){
		if (amount[i] != 0){
			sum += amount[i] * p*pow(r, rlevel[i] - 1);
		}
	}
	printf("%.1f\n", sum);
	return 0;
}