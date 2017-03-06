#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXSIZE 26*26*26*10

vector<int> student[MAXSIZE];

int main()
{
	
	char name[5];
	int i, j, n, k, id, num, size, sid;

	cin >> n >> k;
	for (i = 0; i < k; i++){
		cin >> id >> num;
		for (j = 0; j < num; j++){
			scanf("%s", name);
			sid = (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
			student[sid].push_back(id);
		}
	}
	for (i = 0; i < n; i++){
		scanf("%s", name);
		sid = (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
		cout << name << " ";
		size = student[sid].size();
		cout << size;
		sort(student[sid].begin(), student[sid].end());
		for (j = 0; j < size; j++){
			printf(" %d", student[sid][j]);
		}
		printf("\n");
	}

	return 0;
}