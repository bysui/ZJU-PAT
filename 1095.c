#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define DAY 24*3600

typedef struct Record{
	string id;
	int time;
	int status;
	bool operator < (const Record &r)const{
		return time < r.time;
	}
}Record;

typedef struct Car{
	string id;
	int in, out;
	int total;
	int valid;
	Car(){ 
		in = out = -1;
		valid = 0;
		total = 0;
	}
	bool operator < (const Car &c)const{
		return total > c.total;
	}
}Car;

int n;
map<string, Car> clist;
vector<Record> rdlist;
vector<Record> validRd;
vector<Car> validCar;

int main()
{
	int i, j, k, size, time, cnt;
	int hour, minute, second;
	string id, status;

	scanf("%d %d", &n, &k);
	rdlist.resize(n);
	for (i = 0; i < n; i++){
		cin >> id;
		scanf("%d:%d:%d", &hour, &minute, &second);
		cin >> status;
		rdlist[i].id = id;
		rdlist[i].time = hour * 3600 + minute * 60 + second;
		if (status[0] == 'i')
			rdlist[i].status = 1;
		else
			rdlist[i].status = -1;
	}

	sort(rdlist.begin(), rdlist.end());
	for (i = 0; i < n; i++){
		Record &r = rdlist[i];
		if (r.status == 1){
			if (clist.find(r.id) == clist.end()){
				Car c = Car();
				c.in = r.time;
				c.id = r.id;
				clist[r.id] = c;
			}
			else
				clist[r.id].in = r.time;
		}
		else{
			if (clist.find(r.id) == clist.end()){
				Car c = Car();
				c.out = r.time;
				c.id = r.id;
				clist[r.id] = c;
			}
			else{
				Car &c = clist[r.id];
				c.out = r.time;
				if (c.in != -1 && c.in < c.out){
					Record n1, n2;

					n1.id = n2.id = r.id;
					n1.time = c.in;
					n2.time = c.out;
					n1.status = 1;
					n2.status = -1;
					validRd.push_back(n1);
					validRd.push_back(n2);

					c.total += c.out - c.in;
					c.in = c.out = -1;
					c.valid = 1;				
				}
			}
		}
	}

	sort(validRd.begin(), validRd.end());
	size = validRd.size();
	cnt = 0;
	for (i = 0, j = 0; i < k; i++){
		scanf("%d:%d:%d", &hour, &minute, &second);
		time = hour * 3600 + minute * 60 + second;
		while (j < size && validRd[j].time <= time){
			cnt += validRd[j].status;
			j++;
		}
		printf("%d\n", cnt);
	}
	
	for (map<string, Car>::iterator it = clist.begin(); it != clist.end(); it++){
		Car c = it->second;
		if (c.valid)
			validCar.push_back(c);
	}
	sort(validCar.begin(), validCar.end());
	int max;
	vector<string> res;
	max = validCar[0].total;
	i = 0;
	while (i < validCar.size() && validCar[i].total == max){
		res.push_back(validCar[i].id);
		i++;
	}
	sort(res.begin(), res.end());
	for (i = 0; i < res.size(); i++)
		printf("%s ", res[i].c_str());
	hour = max / 3600;
	minute = max / 60 % 60;
	second = max % 60;
	printf("%02d:%02d:%02d\n", hour, minute, second);
	return 0;
}