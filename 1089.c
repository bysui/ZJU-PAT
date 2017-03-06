#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> seq, res, iseq, mseq;
int n;

bool insertSort()
{
	int i, j, x;
	bool flag;

	flag = false;
	for (i = 1; i < n; i++){
		x = iseq[i];
		j = i - 1;
		while (j >=0 && iseq[j] > x){
			iseq[j + 1] = iseq[j];
			j--;
		}
		iseq[j + 1] = x;
		if (flag)
			break;
		else if (iseq == res)
			flag = true;
	}
	return flag;
}

void mergeSort()
{
	int i, len, start, mid, end;
	bool flag;

	flag = false;
	len = 1;
	while (len < n){
		i = 0;
		while (i < n){
			start = i;
			mid = i + len >= n ? n : i + len;
			end = mid + len >= n ? n : mid + len;
			inplace_merge(mseq.begin() + start, mseq.begin() + mid, mseq.begin() + end);
			i = end;
		}
		len *= 2;
		if (flag)
			break;
		else if (mseq == res)
			flag = true;
	}
}

int main()
{
	int i;

	cin >> n;
	seq.resize(n);
	res.resize(n);
	for (i = 0; i < n; i++)
		cin >> seq[i];
	for (i = 0; i < n; i++)
		cin >> res[i];
	iseq = seq;
	mseq = seq;
	if (insertSort()){
		printf("Insertion Sort\n");
		for (i = 0; i < n - 1; i++)
			printf("%d ", iseq[i]);
		printf("%d\n", iseq[i]);
	}
	else{
		mergeSort();
		printf("Merge Sort\n");
		for (i = 0; i < n - 1; i++)
			printf("%d ", mseq[i]);
		printf("%d\n", mseq[i]);
	}
	return 0;
}