#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> pre, post, res;
bool only;

void buildTree(int prel, int prer, int postl, int postr)
{
	int right, index;

	if (prel == prer){
		res.push_back(pre[prel]);
		return;
	}
	right = post[postr - 1];
	for (index = prel + 1; index <= prer; index++)
		if (pre[index] == right)
			break;
	if (index - prel > 1){
		buildTree(prel + 1, index - 1, postl, postl + index - prel - 2);
		res.push_back(post[postr]);
		buildTree(index, prer, postl + index - prel - 1, postr - 1);
	}
	else{
		only = false;
		res.push_back(post[postr]);
		buildTree(index, prer, postl + index - prel - 1, postr - 1);
	}

}

int main()
{
	int i, j;

	cin >> n;
	pre.resize(n);
	post.resize(n);
	for (i = 0; i < n; i++)
		cin >> pre[i];
	for (i = 0; i < n; i++)
		cin >> post[i];
	only = true;
	buildTree(0, n - 1, 0, n - 1);
	if (only)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << res[0];
	for (i = 1; i < res.size(); i++)
		cout << " " << res[i];
	cout << endl;
	return 0;
}