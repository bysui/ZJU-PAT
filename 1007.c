#include <iostream>
#include <vector>
using namespace std;

vector<int> seq;

int main()
{
	int i, n, tmp, start, end, max, sum;
	bool flag;

	cin >> n;
	seq.resize(n);
	flag = true;
	for (i = 0; i < n; i++){
		cin >> seq[i];
		if (seq[i] >= 0)
			flag = false;
	}
	tmp = start = end = 0;
	max = -1;
	sum = 0;
	for (i = 0; i < n; i++){
		sum += seq[i];
		if (sum < 0){
			sum = 0;
			tmp = i + 1;
		}
		else if (sum > max){
			max = sum;
			start = tmp;
			end = i;
		}
	}
	if (flag)
		printf("%d %d %d\n", 0, seq[0], seq[n - 1]);
	else
		printf("%d %d %d\n", max, seq[start], seq[end]);
	return 0;
}