#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string n1, string n2)
{
	int i, j, len1, len2, carry, sum;
	string result = "";

	len1 = n1.size();
	len2 = n2.size();
	carry = 0;
	for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; i--, j--){
		sum = n1[i] - '0' + n2[j] - '0' + carry;
		result.insert(result.begin(), sum % 10 + '0');
		carry = sum / 10;
	}
	if (carry)
		result.insert(result.begin(), carry + '0');
	return result;
}

int main()
{
	int cnt, k;
	string num, rev;

	cin >> num >> k;

	cnt = 0;
	while (cnt < k){
		rev = num;
		reverse(num.begin(), num.end());
		if (rev == num)
			break;
		else{
			num = add(num, rev);
			cnt++;
		}
	}
	cout << num << endl;
	cout << cnt << endl;
	return 0;
}