#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXSIZE 26*26*26

int weight[MAXSIZE];
bool visit[MAXSIZE];
vector<int> clist[MAXSIZE];
vector<int> cset;
vector<pair<int, int>> res;
int n, k;

int strToint(char *str)
{
	return (str[0] - 'A') * 26 * 26 + (str[1] - 'A') * 26 + str[2] - 'A';
}

void intTostr(int x, char *str)
{
	str[3] = '\0';
	str[2] = x % 26 + 'A';
	str[1] = x / 26 % 26 + 'A';
	str[0] = x / 26 / 26 + 'A';
}

void dfs(int x)
{
	int i, size;

	visit[x] = true;
	cset.push_back(x);
	size = clist[x].size();
	for (i = 0; i < size; i++){
		if (!visit[clist[x][i]])
			dfs(clist[x][i]);
	}
}

int isGang()
{
	int i, size, sum, max, head;

	size = cset.size();
	if (size < 3)
		return -1;
	max = sum = 0;
	head = -1;
	for (i = 0; i < size; i++){
		sum += weight[cset[i]];
		if (max < weight[cset[i]]){
			head = cset[i];
			max = weight[cset[i]];
		}
	}
	if (sum / 2 <= k)
		return -1;
	else
		return head;
}

int main()
{
	int i, w, n1, n2, head, size;
	char name1[4], name2[4];
	queue<int> people;

	cin >> n >> k;
	for (i = 0; i < n; i++){
		scanf("%s %s %d", name1, name2, &w);
		n1 = strToint(name1);
		n2 = strToint(name2);
		weight[n1] += w;
		weight[n2] += w;
		clist[n1].push_back(n2);
		people.push(n1);
	}
	while (!people.empty()){
		cset.clear();
		dfs(people.front());
		people.pop();
		head = isGang();
		if (head != -1)
			res.push_back(make_pair(head, cset.size()));
	}
	sort(res.begin(), res.end());
	size = res.size();
	printf("%d\n", size);
	for (i = 0; i < size; i++){
		intTostr(res[i].first, name1);
		printf("%s %d\n", name1, res[i].second);
	}
	return 0;
}