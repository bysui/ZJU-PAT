#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int graph[201][201];
vector<int> seq, ncount;

bool isHamiltonian()
{
	int i, size, prev;
	
	size = seq.size();
	if (seq[0] != seq[size - 1])
		return false;
	prev = seq[0];
	for (i = 1; i < size; i++){
		if (graph[prev][seq[i]] != 1)
			return false;
		else
			ncount[seq[i]]--;
		prev = seq[i];
	}
	for (i = 1; i <= n; i++){
		if (ncount[i] != 0)
			return false;
	}
	return true;
}

int main()
{
	int i, j, n1, n2, k, cnt;

	cin >> n >> m;
	for (i = 0; i < m; i++){
		cin >> n1 >> n2;
		graph[n1][n2] = graph[n2][n1] = 1;
	}
	cin >> k;
	for (i = 0; i < k; i++){
		cin >> cnt;
		seq.resize(cnt);
		ncount.assign(n + 1, 1);
		for (j = 0; j < cnt; j++)
			cin >> seq[j];
		if (cnt == n + 1 && isHamiltonian())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}