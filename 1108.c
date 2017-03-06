#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isReal(string &str)
{
	int i, start, len, dot;
	double val;

	dot = start = 0;
	len = str.length();
	if (str[start] == '-' || str[start] == '+')
		start++;
	if (start == len)
		return false;
	for (i = start; i < len; i++){
		if (str[i] == '.'){
			dot++;
			if (dot > 1)
				return false;
			if (i - start == 0)
				return false;
			if (len - i - 1 > 2)
				return false;
		}
		else if (str[i] < '0' || str[i] > '9')
			return false;
	}

	sscanf(str.c_str(), "%lf", &val);
	if (val < -1000 || val > 1000)
		return false;
	else
		return true;
}

int main()
{
	int i, j, n, cnt;
	string str;
	double val, sum;

	cin >> n;
	sum = cnt = 0;
	for (i = 0; i < n; i++){
		cin >> str;
		if (isReal(str)){
			cnt++;
			sscanf(str.c_str(), "%lf", &val);
			sum += val;
		}
		else
			cout << "ERROR: " << str << " is not a legal number" << endl;
	}
	if (cnt == 0)
		printf("The average of 0 numbers is Undefined\n");
	else if (cnt == 1)
		printf("The average of 1 number is %.2f\n", sum);
	else
		printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
	return 0;
}