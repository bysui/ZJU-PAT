#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int i, j, k, n, m;
	vector<int> seq;
	bool flag;

	cin >> n;
	for (i = 0; i < n; ++i){
		cin >> m;
		seq.resize(m);
		for (j = 0; j < m; ++j)
			cin >> seq[j];
		flag = true;
		for (j = 0; j < m; ++j){
			for (k = j + 1; k < m; ++k){
				if (abs(k - j) == abs(seq[k] - seq[j])){
					flag = false;
					break;
				}
				if (seq[k] == seq[j]){
					flag = false;
					break;
				}
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}