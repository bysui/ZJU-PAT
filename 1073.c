#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string exp, str, ans, num, sexp;
	stringstream ss;
	int i, eid, iexp;

	getline(cin, str);
	ans = "";
	if (str[0] == '-')
		ans += str[0];
	eid = str.find("E");
	num = str.substr(1, eid - 1);
	sexp = str.substr(eid + 2, str.size() - eid - 2);
	ss << sexp;
	ss >> iexp;
	if (iexp == 0){
		cout << ans << num << endl;
		return 0;
	}
	if (str[eid + 1] == '+'){
		if (iexp < num.size() - 2)
			ans += num[0] + num.substr(2, iexp) + '.' + num.substr(iexp + 2, num.size() - iexp - 2);
		else{
			ans += num[0] + num.substr(2, num.size() - 2);
			for (i = 0; i < iexp - num.size() + 2; i++)
				ans += '0';
		}
	}
	else if (str[eid + 1] == '-'){
		ans += "0.";
		for (i = iexp; i > 1; i--)
			ans += '0';
		ans += num[0] + num.substr(2, num.size() - 2);
	}
	cout << ans << endl;
	return 0;
}