#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, root, level, num;
double p, r;
vector<vector<int>> chain;

void bfs(int src)
{
	int i, id, len, head;
	bool first;
	queue<int> list;

	list.push(src);
	head = src;
	first = true;
	while (!list.empty()){
		id = list.front();
		list.pop();
		if (head == id){
			level++;
			num = 0;
			first = true;
		}
		num++;
		len = chain[id].size();
		for (i = 0; i < len; i++){
			list.push(chain[id][i]);
			if (first){
				head = chain[id][i];
				first = false;
			}
		}
	}
}

int main()
{
	int i, id;

	cin >> n >> p >> r;
	r = 1 + 0.01 * r;
	chain.resize(n);
	for (i = 0; i < n; i++){
		cin >> id;
		if (id != -1)
			chain[id].push_back(i);
		else
			root = i;
	}
	bfs(root);
	printf("%.2f %d\n", p * pow(r, level - 1), num);
	return 0;
}