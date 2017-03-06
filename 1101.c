#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Inf 1<<30

vector<int> seq;
vector<int> dp1, dp2;
vector<int> res;
int n;

int main()
{
	int i, j, cnt;
	
	cin >> n;
	seq.resize(n + 2);
	dp1.resize(n + 2);
	dp2.resize(n + 2);
	for (i = 1; i <= n; i++){
		cin >> seq[i];
		dp1[i] = dp2[i] = seq[i];
	}
	dp1[0] = -Inf;
	dp2[n + 1] = Inf;
	for (i = 2; i <= n; i++){
		dp1[i] = max(dp1[i], dp1[i - 1]);
		dp2[n - i] = min(dp2[n - i], dp2[n + 1 - i]);
	}
	cnt = 0;
	for (i = 1; i <= n; i++){
		if (dp1[i - 1] < seq[i] && dp2[i + 1] > seq[i]){
			cnt++;
			res.push_back(seq[i]);
		}
	}
	printf("%d\n", cnt);
	if (cnt > 0){
		for (i = 0; i < cnt - 1; i++)
			printf("%d ", res[i]);
		printf("%d", res[i]);
	}
	printf("\n");
	return 0;
}