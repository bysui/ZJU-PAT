#include <iostream>
#include <vector>
using namespace std;

int n, m, res, gern;
vector<vector<int>> family;

void bfs(int root)
{
	vector<int> v1, v2;
	int i, j, len, level, count;

	v1.push_back(root);
	gern = level = 1;
	res = 1;
	while (v1.size() > 0){
		level++;
		len = v1.size();
		for (i = 0; i < len; i++)
			v2.insert(v2.end(), family[v1[i]].begin(), family[v1[i]].end());
		if (v2.size() > res){
			res = v2.size();
			gern = level;
		}
		v1 = v2;
		v2.clear();
	}
}

int main()
{
	int i, j, id, cid, k;

	cin >> n >> m;
	family.resize(n + 1);
	for (i = 0; i < m; i++){
		cin >> id >> k;
		for (j = 0; j < k; j++){
			cin >> cid;
			family[id].push_back(cid);
		}
	}
	bfs(1);
	printf("%d %d\n", res, gern);
	return 0;
}