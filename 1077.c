#include <iostream>
#include <string>
using namespace std;

int main()
{
	string common, input, last;
	int i, n, index1, index2, len, flag;

	cin >> n;
	getchar();
	getline(cin, last);
	common = last;
	
	flag = 1;
	for (i = 1; i < n; i++){
		getline(cin, input);
		if (flag){
			index1 = last.length() - 1;
			index2 = input.length() - 1;
			while (last[index1] == input[index2]){
				index1--;
				index2--;
			}
			len = last.length() - index1 - 1;
			if (len == 0){
				common = "nai";
				flag = 0;
			}
			else if (common.length() > len)
				common = last.substr(index1 + 1);
		}
	}
	cout << common << endl;
	return 0;
}