#include <cstdio>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

set<int> list[50];
int main()
{
	int i, j, count, v, n, m, s1, s2;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &count);
		for (j = 0; j < count; j++){
			scanf("%d", &v);
			list[i].insert(v);
		}
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++){
		int usize, isize;
		set<int> uset;
		scanf("%d %d", &s1, &s2);
		s1--;
		s2--;
		isize = 0;
		for (set<int>::iterator it = list[s1].begin(); it != list[s1].end(); it++){
			if (list[s2].find(*it) != list[s2].end())
				isize++;
		}
		usize = list[s1].size() + list[s2].size() - isize;
		printf("%.1f%%\n", isize * 100.0 / usize);
	}
	return 0;
}