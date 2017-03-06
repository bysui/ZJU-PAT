#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Family{
	int pid, pcount, sets, area, mid;
	bool exist;
	Family(){
		pid = -1;
		pcount = 1;
		sets = area = 0;
		exist = false;
	}
}Family;

int n, m;
Family plist[10000];
vector<int> res;

int findRoot(int x)
{
	if (plist[x].pid == -1)
		return x;
	else
		return plist[x].pid = findRoot(plist[x].pid);
}

void unionRoot(int r1, int r2)
{
	plist[r2].pid = r1;
	plist[r1].pcount += plist[r2].pcount;
	if (plist[r2].mid < plist[r1].mid)
		plist[r1].mid = plist[r2].mid;
}

bool comp(int x, int y)
{
	double a1, a2;

	a1 = plist[x].area * 1.0 / plist[x].pcount;
	a2 = plist[y].area * 1.0 / plist[y].pcount;
	if (a1 == a2)
		return plist[x].mid < plist[y].mid;
	else
		return a1 > a2;
}

int main()
{
	int i, j, id, nid, kcnt, estate, money;
	int r1, r2, count;

	cin >> n;
	for (i = 0; i < 10000; i++)
		plist[i].mid = i;

	for (i = 0; i < n; i++){
		cin >> id;
		plist[id].exist = true;
		r1 = findRoot(id);
		for (j = 0; j < 2; j++){
			cin >> nid;
			if (nid != -1){
				plist[id].exist = true;
				r2 = findRoot(nid);
				if (r1 != r2)
					unionRoot(r1, r2);
			}
		}
		cin >> kcnt;
		for (j = 0; j < kcnt; j++){
			cin >> nid;
			if (nid != -1){
				plist[id].exist = true;
				r2 = findRoot(nid);
				if (r1 != r2)
					unionRoot(r1, r2);
			}
		}
		cin >> estate >> money;
		plist[id].sets = estate;
		plist[id].area = money;
	}
	count = 0;
	for (i = 0; i < 10000; i++){
		if (plist[i].exist){
			if (plist[i].pid != -1){
				r1 = findRoot(i);
				plist[r1].sets += plist[i].sets;
				plist[r1].area += plist[i].area;
			}
			else{
				count++;
				res.push_back(i);
			}
		}
	}
	sort(res.begin(), res.end(), comp);
	cout << count << endl;
	for (i = 0; i < count; i++)
		printf("%04d %d %.3f %.3f\n", plist[res[i]].mid, plist[res[i]].pcount, plist[res[i]].sets *1.0 / plist[res[i]].pcount, plist[res[i]].area * 1.0 / plist[res[i]].pcount);
	return 0;
}