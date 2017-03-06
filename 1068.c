#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int map[10001][101];
bool has[10001][101];
vector<int> coin, res;

int main()
{
	int i, j, n, m, value;;

	scanf("%d %d", &n, &m);
	coin.resize(n + 1);
	for (i = 1; i <= n; i++)
		scanf("%d", &coin[i]);
	sort(coin.begin() + 1, coin.end(), greater<int>());
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			if (j - coin[i] < 0)
				value = 0;
			else
				value = map[i - 1][j - coin[i]] + coin[i];
			if (map[i - 1][j] > value)
				map[i][j] = map[i - 1][j];
			else{
				map[i][j] = value;
				has[i][j] = true;
			}
		}
	}

	if (map[n][m] == m){
		while (m){
			while (!has[n][m])
				n--;
			res.push_back(coin[n]);
			m -= coin[n];
			n--;
		}
		for (i = 0; i < res.size() - 1; i++)
			printf("%d ", res[i]);
		printf("%d\n", res[i]);
	}
	else
		printf("No Solution\n");
	return 0;
}