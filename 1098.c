#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n;
vector<int> input, seq, iseq, hseq;

bool insertSort()
{
	int i, j, val;
	bool flag;

	flag = false;
	iseq = input;
	for (i = 1; i < n; i++){
		val = iseq[i];
		j = i - 1;
		while (j >= 0 && val < iseq[j]){
			iseq[j + 1] = iseq[j];
			j--;
		}
		iseq[j + 1] = val;
		if (flag)
			break;
		if (iseq == seq)
			flag = true;
	}
	return flag;
}

void heapSort()
{
	int i;
	bool flag;

	flag = false;
	hseq = input;
	make_heap(hseq.begin(), hseq.end());
	for (i = 0; i < n; i++){
		pop_heap(hseq.begin(), hseq.end() - i);
		if (flag)
			break;
		if (hseq == seq)
			flag = true;
	}
}

int main()
{
	int i;

	cin >> n;
	input.resize(n);
	seq.resize(n);
	for (i = 0; i < n; i++)
		cin >> input[i];
	for (i = 0; i < n; i++)
		cin >> seq[i];
	if (insertSort()){
		cout << "Insertion Sort" << endl;
		for (i = 0; i < n - 1; i++)
			cout << iseq[i] << " ";
		cout << iseq[i] << endl;
	}
	else{
		heapSort();
		cout << "Heap Sort" << endl;
		for (i = 0; i < n - 1; i++)
			cout << hseq[i] << " ";
		cout << hseq[i] << endl;
	}
	return 0;
}