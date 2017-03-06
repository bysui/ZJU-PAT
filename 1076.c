#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> weibo;
vector<bool> visit;
int n, l;

int bfs(int x)
{
	queue<int> list;
	int i, level, cnt, id, first, last;

	visit.assign(n + 1, false);
	cnt = 1;
	first = level = 0;
	last = 1;
	list.push(x);
	visit[x] = true;
	while (!list.empty()){
		id = list.front();
		list.pop();
		first++;
		for (i = 0; i < weibo[id].size(); i++){
			if (!visit[weibo[id][i]]){
				list.push(weibo[id][i]);
				visit[weibo[id][i]] = true;;
				cnt++;
			}
		}
		if (first == last){
			last = cnt;
			level++;
		}
		if (level == l)
			break;
	}
	return cnt - 1;
}

int main()
{
	int i, j, id, total, k, cnt;

	cin >> n >> l;
	weibo.resize(n + 1);
	for (i = 1; i <= n; i++){
		cin >> total;
		for (j = 0; j < total; j++){
			cin >> id;
			weibo[id].push_back(i);
		}
	}
	
	cin >> k;
	for (i = 0; i < k; i++){
		cin >> id;
		cnt = bfs(id);
		cout << cnt << endl;
	}
	return 0;
}