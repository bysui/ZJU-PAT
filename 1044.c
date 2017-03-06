#include <iostream>
#include <vector>
using namespace std;

#define Inf 1<<30

vector<int> sum;
vector<int> sid, dest;
int n, m;

int findMinSum(int start)
{
	int left, right, mid;

	left = start + 1;
	right = n;
	while (left < right){
		mid = (left + right) / 2;
		if (sum[mid] - sum[start] >= m)
			right = mid;
		else
			left = mid + 1;
	}
	dest[start] = right;
	return sum[right] - sum[start];
}

int main()
{
	int i, v, id, min;

	scanf("%d %d", &n, &m);
	sum.assign(n + 1, 0);
	dest.resize(n + 1);
	for (i = 1; i <= n; i++){
		scanf("%d", &v);
		sum[i] = sum[i - 1] + v;
	}
	min = Inf;
	for (i = 0; i < n; i++){
		id = findMinSum(i);
		if (id >= m){
			if (id == min)
				sid.push_back(i);
			else if(id < min){
				min = id;
				sid.clear();
				sid.push_back(i);
			}
		}
		else
			break;
	}
	for (i = 0; i < sid.size(); i++)
		printf("%d-%d\n", sid[i] + 1, dest[sid[i]]);
	return 0;
}