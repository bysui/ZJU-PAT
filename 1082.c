#include<iostream>
#include<vector>
#include<string>
using namespace std;

string digit[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string bit[] = { "", "Shi", "Bai", "Qian", "", "Wan", "Yi" };

int main(){
	int i, j, n, flag, len;
	vector<int> num;
	vector<string> res;
	
	cin >> n;
	if (n == 0){
		cout << "ling" << endl;
		return 0;
	}
	if (n < 0){
		cout << "Fu ";
		n = -n;
	}
	while (n){
		num.push_back(n % 10);
		n /= 10;
	}

	i = 0;
	len = num.size();
	while (i < len){
		flag = 0;
		if (i > 0) 
			res.push_back(bit[i / 4 + 4]);
		j = 0;
		while (j < 4 && i + j < len){
			if (num[i + j] == 0){
				if (flag){
					res.push_back("ling");
					flag = 0;
				}
			}
			else{
				if (j > 0) 
					res.push_back(bit[j]);
				res.push_back(digit[num[i + j]]);
				flag = 1;
			}
			j++;
		}
		i += j;
	}
	for (i = res.size() - 1; i >= 0; i--){
		if (i < res.size() - 1)
			cout << " ";
		cout << res[i];
	}
	cout << endl;
	return 0;
}