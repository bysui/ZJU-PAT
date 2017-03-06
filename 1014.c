#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define Inf 1<<30

typedef struct Customer{
	int process;
	int leave;
}Customer;

int n, m, k, q;
vector<Customer> cus;
vector<queue<int>> winQueue;
vector<int> timeBase;

int main()
{
	int i, j, p, mmin, index, top, qid;

	scanf("%d%d%d%d", &n, &m, &k, &q);
	cus.resize(k);
	winQueue.resize(n);
	timeBase.assign(n, 0);
	for (i = 0; i < k; i++){
		scanf("%d", &cus[i].process);
		cus[i].leave = Inf;
	}
	
	for (p = 0; p < n * m && p < k; p++){
		cus[p].leave = timeBase[p%n] + cus[p].process;
		timeBase[p%n] = cus[p].leave;
		winQueue[p%n].push(p);
	}

	for (; p < k; p++){
		mmin = Inf;
		index = -1;
		for (j = 0; j < n; j++){
			top = winQueue[j].front();
			if (mmin > cus[top].leave){
				index = j;
				mmin = cus[top].leave;
			}
		}
		cus[p].leave = timeBase[index] + cus[p].process;
		timeBase[index] = cus[p].leave;
		winQueue[index].pop();
		winQueue[index].push(p);
	}

	for (i = 0; i < q; i++){
		scanf("%d", &qid);
		qid--;
		if (cus[qid].leave - cus[qid].process >= 540)
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", 8 + cus[qid].leave / 60, cus[qid].leave % 60);
	}
	return 0;
}