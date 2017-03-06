#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> seq;

int main()
{
	int i, sum;
	
	cin >> n;
	seq.resize(n);
	for (i = 0; i < n; i++)
		cin >> seq[i];
	sort(seq.begin(), seq.end());
	sum = seq[0];
	for (i = 1; i < n; i++)
		sum = (sum + seq[i]) / 2;
	cout << sum << endl;
	return 0;
}