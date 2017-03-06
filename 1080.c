#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
	int id;
	int g1, g2;
	int total;
	int choice[5];
}Student;

vector<Student> stuList;
vector<vector<int>> schoolList;
int contain[100];

bool comp(Student &s1, Student &s2)
{
	if (s1.total == s2.total)
		return s1.g1 > s2.g1;
	else
		return s1.total > s2.total;
}

bool compid(int id1, int id2)
{
	return stuList[id1].id < stuList[id2].id;
}

int main()
{
	int i, j, n, m, k ,sid, pid;
	int size;
	scanf("%d %d %d", &n, &m, &k);
	stuList.resize(n);
	schoolList.resize(m);
	for (i = 0; i < m; i++)
		scanf("%d", &contain[i]);
	for (i = 0; i < n; i++){
		scanf("%d %d", &stuList[i].g1, &stuList[i].g2);
		stuList[i].total = stuList[i].g1 + stuList[i].g2;
		stuList[i].id = i;
		for (j = 0; j < k; j++){
			scanf("%d", &sid);
			stuList[i].choice[j] = sid;
		}
	}
	sort(stuList.begin(), stuList.end(), comp);
	for (i = 0; i < n; i++){
		for(j = 0; j < k; j++){
			pid = stuList[i].choice[j];
			if (contain[pid] > 0){
				contain[pid]--;
				schoolList[pid].push_back(i);
				break;
			}
			else{
				sid = schoolList[pid][schoolList[pid].size() - 1];
				if (stuList[sid].total == stuList[i].total&&stuList[sid].g1 == stuList[i].g1){
					contain[pid]--;
					schoolList[pid].push_back(i);
					break;
				}
			}
		}
	}
	for (i = 0; i < m; i++){
		size = schoolList[i].size();
		if (size > 0){
			sort(schoolList[i].begin(), schoolList[i].end(), compid);
			for (j = 0; j < size - 1; j++)
				printf("%d ", stuList[schoolList[i][j]].id);
			printf("%d\n", stuList[schoolList[i][j]].id);
		}
		else
			printf("\n");
	}
	return 0;
}