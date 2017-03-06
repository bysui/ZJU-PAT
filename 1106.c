#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> chain;
vector<int> level;
vector<int> retailer;
int n;
double p, r;

int updateLevel(int id)
{
	if (level[id] == -1){
		if (chain[id] == -1)
			return 0;
		else
			return level[id] = updateLevel(chain[id]) + 1;
	}
	else
		return level[id];
}

int main()
{
	int i, j, id, cnt, size;
	int mlevel, sum;

	cin >> n >> p >> r;
	r  = r /100 + 1;
	chain.assign(n, -1);
	level.assign(n, -1);
	for (i = 0; i < n; i++){
		cin >> cnt;
		for (j = 0; j < cnt; j++){
			cin >> id;
			chain[id] = i;
		}
		if (cnt == 0)
			retailer.push_back(i);
	}
	size = retailer.size();
	mlevel = n;
	sum = 0;
	for (i = 0; i < size; i++){
		level[retailer[i]] = updateLevel(retailer[i]);
		if (level[retailer[i]] == mlevel)
			sum++;
		else if (level[retailer[i]] < mlevel){
			sum = 1;
			mlevel = level[retailer[i]];
		}
	}
	printf("%.4f %d\n", p * pow(r, mlevel), sum);
	return 0;
}