#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define CloseTime 17*3600
#define Inf 1<<30 

typedef struct People{
	int arrive, serve, start;
	bool operator < (const People &p)const{
		return arrive < p.arrive;
	}
}People;

int n, k;
vector<int> windows;
vector<People> line;

int main()
{
	int i, id, size, mintime, fid, wait, stime;
	int hour, minute, second, ptime;

	scanf("%d %d", &n, &k);
	windows.assign(k, 8*3600);
	for (i = 0; i < n; i++){
		People p;
		scanf("%d:%d:%d %d", &hour, &minute, &second, &ptime);
		p.arrive = hour * 3600 + minute * 60 + second;
		p.serve = ptime <= 60 ? ptime * 60 : 3600;
		p.start = 0;
		if (p.arrive < CloseTime)
			line.push_back(p);
	}
	
	sort(line.begin(), line.end());
	id = 0;
	wait = 0;
	size = line.size();
	while (id < size){
		stime = mintime = Inf;
		fid = -1;
		for (i = 0; i < k; i++){
			if (windows[i] < mintime){
				mintime = windows[i];
				fid = i;
			}
		}
		if (line[id].arrive < mintime)
			stime = mintime;
		else
			stime = line[id].arrive;
		line[id].start = stime;
		windows[fid] = stime + line[id].serve;
		wait += line[id].start - line[id].arrive;
		id++;
	}

	printf("%.1f\n", wait /60.0 / id);
	return 0;
}