#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

typedef struct Person{
	string name;
	int height;
	bool operator < (const Person &p)const{
		if (height == p.height)
			return name < p.name;
		else
			return height > p.height;
	}
}Person;

int n, k;
vector<Person> plist;
vector<vector<int>> group;

int main()
{
	int i, j, row, len, index;
	

	cin >> n >> k;
	plist.resize(n);
	for (i = 0; i < n; i++)
		cin >> plist[i].name >> plist[i].height;
	sort(plist.begin(), plist.end());
	
	row = k;
	len = n % k + n / k;
	index = 0;
	group.resize(n);
	for (i = 0; i < row; i++){
		for (j = 0; j < len; j++){
			if (j % 2)
				group[i].insert(group[i].begin(), index);
			else
				group[i].push_back(index);
			index++;
		}
		len = n / k;
	}
	for (i = 0; i < row; i++){
		for (j = 0; j < group[i].size(); j++){
			cout << plist[group[i][j]].name;
			if (j < group[i].size() - 1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}