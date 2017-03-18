#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	int i, j, n, k, x;
	vector<int> seq, count, res;
	
	cin >> n >> k;
	seq.resize(n);
	count.assign(n + 1, 0);
	for (i = 0; i < n; ++i)
		cin >> seq[i];
	count[seq[0]]++;
	res.push_back(seq[0]);
	for (i = 1; i < n; ++i){
		x = seq[i];
		cout << x << ":";
		for (auto it : res)
			cout << " " << it;
		cout << endl;
		count[x]++;
		auto pos = find(res.begin(), res.end(), x) - res.begin();
		if (pos >= res.size()){
			res.push_back(x);
			pos = res.size() - 1;
		}
		for (j = pos - 1; j >= 0; --j){
			if (count[x]>count[res[j]] || (count[x] == count[res[j]] && x < res[j])){
				res[j + 1] = res[j];
				res[j] = x;
			}
		}
		if (res.size() > k)
			res.pop_back();
	}
	return 0;
}