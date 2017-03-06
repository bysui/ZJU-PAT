#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
	char name[5];
}Student;

vector<Student> stu;

bool comp(int s1, int s2)
{
	return strcmp(stu[s1].name, stu[s2].name) < 0;
}

int main()
{
	int i, j, k, id, sz, n, m;
	char name[5];
	vector<vector<int>> course(2500);

	scanf("%d %d", &n, &m);
	stu.resize(n);
	course.resize(m);
	for (i = 0; i < n; i++){
		scanf("%s %d", stu[i].name, &k);
		for (j = 0; j < k; j++){
			scanf("%d", &id);
			course[id - 1].push_back(i);
		}
	}
	sz = course.size();
	for (i = 0; i < course.size(); i++){
		k = course[i].size();
		printf("%d %d\n", i + 1, k);
		sort(course[i].begin(), course[i].end(), comp);
		for (j = 0; j < k; j++)
			printf("%s\n", stu[course[i][j]].name);
	}
	return 0;
}