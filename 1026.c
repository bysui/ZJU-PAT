#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define CloseTime 21*3600

typedef struct Player{
	int arrive, serve;
	int start;
	bool operator < (const Player &p)const{
		return arrive < p.arrive;
	}
}Player;

typedef struct Table{
	int free, serve;
	bool vip;
	Table(){
		free = 8 * 60 * 60;
		serve = 0;
		vip = false;
	}
}Table;

vector<Player> normal;
vector<Player> vip;
vector<Table> tlist;
int n, k, m;

void outPutTime(int time)
{
	int hour, minute, second;

	hour = time / 60 / 60;
	minute = time / 60 % 60;
	second = time % 60;
	printf("%02d:%02d:%02d ", hour, minute, second);
}

void outPut(Player &id)
{
	outPutTime(id.arrive);
	outPutTime(id.start);
	printf("%d\n", (id.start - id.arrive + 30) / 60);
}

int main()
{
	int i, j, t, nsize, vsize, vid, mintime;
	int hour, minute, second ,ptime, isvip;
	int fid, ntime, vtime;
	bool vipserve;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		Player p;
		scanf("%d:%d:%d %d %d", &hour, &minute, &second, &ptime, &isvip);
		p.arrive = hour * 60 * 60 + minute * 60 + second;
		p.serve = ptime <= 120 ? ptime * 60 : 120 * 60;
		if (isvip)
			vip.push_back(p);
		else
			normal.push_back(p);
	}
	scanf("%d %d", &k, &m);
	tlist.resize(k);
	for (i = 0; i < m; i++){
		scanf("%d", &vid);
		tlist[vid - 1].vip = true;
	}

	sort(normal.begin(), normal.end());
	sort(vip.begin(), vip.end());
	nsize = normal.size();
	vsize = vip.size();
	i = j = 0;
	while (i < nsize || j < vsize){
		ntime = vtime = mintime = CloseTime;
		fid = -1;
		for (t = 0; t < k; t++){
			if (tlist[t].free < mintime){
				mintime = tlist[t].free;
				fid = t;
			}
		}
		if (i < nsize){
			ntime = normal[i].arrive;
			if (ntime < mintime)
				ntime = mintime;
		}
		if (j < vsize){
			vtime = vip[j].arrive;
			if (vtime < mintime)
				vtime = mintime;
		}
		vipserve = true;
		if (ntime < vtime && ntime < CloseTime)
			vipserve = false;
		else if (vtime < ntime && vtime < CloseTime)
			vipserve = true;
		else if (ntime == vtime && ntime < CloseTime){
			if (tlist[fid].vip || (!tlist[fid].vip && vip[j].arrive < normal[i].arrive))
				vipserve = true;
			else
				vipserve = false;
		}
		else if (ntime == vtime && ntime == CloseTime)
			break;

		if (vipserve){
			if (!tlist[fid].vip){
				for (t = 0; t < k; t++){
					if (tlist[t].vip&&tlist[t].free == mintime)
						fid = t;
				}
			}
			vip[j].start = vtime;
			tlist[fid].free = vtime + vip[j].serve;
			tlist[fid].serve++;
			outPut(vip[j]);
			j++;
		}
		else{
			normal[i].start = ntime;
			tlist[fid].free = ntime + normal[i].serve;
			tlist[fid].serve++;
			outPut(normal[i]);
			i++;
		}
	}
	for (i = 0; i < k - 1; i++)
		printf("%d ", tlist[i].serve);
	printf("%d\n", tlist[i].serve);
	return 0;
}