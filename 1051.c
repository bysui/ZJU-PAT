#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;

int main()
{
	int i, j, n, m, k, index, flag;
	int *seq;

	cin >> m >> n >> k;
	seq = new int[n];
	for (i = 0; i < k; i++){
		for (j = 0; j < n; j++)
			cin >> seq[j];
		flag = 1;
		index = 1;
		j = 0;
		while (flag && j < n){
			while (stk.empty() || stk.size() <= m && stk.top() != seq[j])
				stk.push(index++);
			if (stk.size() > m)
				flag = 0;
			else{
				stk.pop();
				j++;
			}
		}
		if (j == n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		while (!stk.empty())
			stk.pop();
	}
	delete[]seq;
	return 0;
}