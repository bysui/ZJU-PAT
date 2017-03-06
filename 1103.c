#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, p;
int tcnt, tsum, rsum;
vector<int> tfactor, rfactor;

int ipow(int x)
{
	int i, res;
	
	res = 1;
	for (i = 1; i <= p; i++)
		res *= x;
	return res;
}

void dfs(int val, int flast)
{
	int i, up, low, res;

	if (tcnt == k){
		if (val == 0){
			if (tsum >= rsum){
				rsum = tsum;
				rfactor = tfactor;
			}
		}
		return;
	}

	up = sqrt((double)val);
	low = flast;
	for (i = low; i <= up; i++){
		res = ipow(i);
		if (res <= val){
			tfactor.push_back(i);
			tsum += i;
			tcnt++;
			dfs(val - res, i);
			tfactor.pop_back();
			tsum -= i;
			tcnt--;
		}
		else
			break;
	}
}

int main()
{
	int i, j;
		
	cin >> n >> k >> p;
	tsum = tcnt = 0;
	rsum = -1;
	dfs(n, 1);
	reverse(rfactor.begin(), rfactor.end());
	if (rfactor.size() == k){
		printf("%d = %d^%d", n, rfactor[0], p);
		for (i = 1; i < k; i++)
			printf(" + %d^%d", rfactor[i], p);
		printf("\n");
	}
	else
		printf("Impossible\n");
	return 0;
}