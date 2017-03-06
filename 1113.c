#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> seq;

int main()
{
	int i, j, sum ,half;

	cin >> n;
	seq.resize(n);
	sum = 0;
	for (i = 0; i < n; i++){
		cin >> seq[i];
		sum += seq[i];
	}
	sort(seq.begin(), seq.end());
	half = 0;
	for (i = 0; i < n / 2; i++)
		half += seq[i];
	cout << n % 2 << " " << sum - 2 * half;
	return 0;
}