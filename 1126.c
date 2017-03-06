#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> graph, degree;

int findRoot(int x)
{
	if (graph[x] == -1)
		return x;
	else
		return graph[x] = findRoot(graph[x]);
}

bool isConnect()
{
	int i, count;

	for (i = 1, count = 0; i <= n; i++)
		if (graph[i] == -1)
			count++;
	if (count > 1)
		return false;
	else
		return true;
}

int getDegree()
{
	int i, count;

	for (i = 1, count = 0; i <= n; i++)
		if (degree[i] % 2 == 1)
			count++;
	return count;
}

int main()
{
	int i, v1, v2;
	int r1, r2;

	cin >> n >> m;
	graph.assign(n + 1, -1);
	degree.assign(n + 1, 0);
	for (i = 0; i < m; i++){
		cin >> v1 >> v2;
		degree[v1]++;
		degree[v2]++;
		r1 = findRoot(v1);
		r2 = findRoot(v2);
		if (r1 != r2)
			graph[r2] = r1;
	}
	cout << degree[1];
	for (i = 2; i <= n; i++)
		cout << " " << degree[i];
	cout << endl;
	if (isConnect() && getDegree() == 0)
		cout << "Eulerian" << endl;
	else if (isConnect() && getDegree() == 2)
		cout << "Semi-Eulerian" << endl;
	else
		cout << "Non-Eulerian" << endl;
	return 0;
}