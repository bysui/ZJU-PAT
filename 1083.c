#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
	char name[11];
	char id[11];
	int grade;
}Student;

vector<Student> list;

bool comp(const Student &s1, const Student &s2)
{
	return s1.grade > s2.grade;
}

int main()
{
	int i, n, low, high, count;

	scanf("%d", &n);
	list.resize(n);
	for (i = 0; i < n; i++)
		scanf("%s %s %d", list[i].name, list[i].id, &list[i].grade);
	scanf("%d %d", &low, &high);

	sort(list.begin(), list.end(), comp);
	i = 0;
	count = 0;
	while (i < n && list[i].grade > high)
		i++;
	while (i < n && list[i].grade >= low){
		printf("%s %s\n", list[i].name, list[i].id);
		i++;
		count++;
	}
	if (count == 0)
		printf("NONE\n");
	return 0;
}