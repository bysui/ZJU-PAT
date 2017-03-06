#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n;
int damn[100000];
vector<int> seq, res;

int main()
{
	int i, m, n1, n2;

	cin >> n;
	fill(damn, damn + 100000, -1);
	for (i = 0; i < n; i++){
		cin >> n1 >> n2;
		damn[n1] = n2;
		damn[n2] = n1;
	}
	cin >> m;
	seq.resize(m);
	for (i = 0; i < m; i++)
		cin >> seq[i];
	for (i = 0; i < m; i++){
		if (damn[seq[i]] == -1)
			res.push_back(seq[i]);
		else{
			if (find(seq.begin(), seq.end(), damn[seq[i]]) == seq.end())
				res.push_back(seq[i]);
		}
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (i = 0; i < res.size(); i++){
		printf("%05d", res[i]);
		if (i != res.size() - 1)
			printf(" ");
	}
	
	return 0;
}