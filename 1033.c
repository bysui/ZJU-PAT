#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Inf 1<<30

typedef struct GasStation{
	double price;
	int dist;
	bool operator < (const GasStation& a)const{
		return dist < a.dist;
	}
}GasStation;

vector<GasStation> glist;
int n;
double cmax, dist, davg;

int main()
{
	int i, gid;
	double now, can, mprice, mid, cleft, fee;
	bool find;

	cin >> cmax >> dist >> davg >> n;
	glist.resize(n + 1);
	for (i = 0; i < n; i++)
		cin >> glist[i].price >> glist[i].dist;
	glist[n].price = 0;
	glist[n].dist = dist;
	sort(glist.begin(), glist.end());

	if (glist[0].dist != 0){
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	
	fee = cleft = now = 0;
	gid = 0;
	while (now < dist){
		can = now + cmax * davg;
		if (glist[gid + 1].dist > can){
			printf("The maximum travel distance = %.2f\n", can);
			return 0;
		}
		find = false;
		mprice = Inf;
		for (i = gid + 1; gid <= n && glist[i].dist <= can; i++){
			if (glist[i].price <= mprice){
				mprice = glist[i].price;
				mid = i;
				if (glist[i].price < glist[gid].price){
					find = true;
					break;
				}
			}
		}
		if (find){
			fee += ((glist[mid].dist - now) / davg - cleft) * glist[gid].price;
			cleft = 0;
			
		}
		else{
			fee += (cmax - cleft) * glist[gid].price;
			cleft = cmax - (glist[mid].dist - now) / davg;
		}
		now = glist[mid].dist;
		gid = mid;
	}
	printf("%.2f\n", fee);
	return 0;
}#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Inf 1<<30

typedef struct GasStation{
	double price;
	int dist;
	bool operator < (const GasStation& a)const{
		return dist < a.dist;
	}
}GasStation;

vector<GasStation> glist;
int n;
double cmax, dist, davg;

int main()
{
	int i, gid;
	double now, can, mprice, mid, cleft, fee;
	bool find;

	cin >> cmax >> dist >> davg >> n;
	glist.resize(n + 1);
	for (i = 0; i < n; i++)
		cin >> glist[i].price >> glist[i].dist;
	glist[n].price = 0;
	glist[n].dist = dist;
	sort(glist.begin(), glist.end());

	if (glist[0].dist != 0){
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	
	fee = cleft = now = 0;
	gid = 0;
	while (now < dist){
		can = now + cmax * davg;
		if (glist[gid + 1].dist > can){
			printf("The maximum travel distance = %.2f\n", can);
			return 0;
		}
		find = false;
		mprice = Inf;
		for (i = gid + 1; gid <= n && glist[i].dist <= can; i++){
			if (glist[i].price <= mprice){
				mprice = glist[i].price;
				mid = i;
				if (glist[i].price < glist[gid].price){
					find = true;
					break;
				}
			}
		}
		if (find){
			fee += ((glist[mid].dist - now) / davg - cleft) * glist[gid].price;
			cleft = 0;
			
		}
		else{
			fee += (cmax - cleft) * glist[gid].price;
			cleft = cmax - (glist[mid].dist - now) / davg;
		}
		now = glist[mid].dist;
		gid = mid;
	}
	printf("%.2f\n", fee);
	return 0;
}