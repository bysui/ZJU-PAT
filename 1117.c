#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n;
vector<int> seq;

int main()
{
	int i, emax;

	cin >> n;
	seq.resize(n + 1);
	for (i = 1; i <= n; i++)
		cin >> seq[i];
	sort(seq.begin() + 1, seq.end(), greater<int>());
	emax = n;
	while (emax >= 1 && seq[emax] <= emax)
		emax--;
	cout << emax << endl;;
	return 0;
}