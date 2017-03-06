#include <iostream>
#include <string>
using namespace std;

int broken[256];

int main()
{
	int i, j, k, len, cnt;
	string str;

	cin >> k >> str;
	len = str.length();
	i = 0;
	for (i = 0; i < len; i++){
		if (i + k > len){
			broken[str[i]] = -1;
			continue;
		}
		if (broken[str[i]] != -1){
			broken[str[i]] = 1;
			for (j = 1; j < k; j++)
				if (str[i + j] != str[i])
					broken[str[i]] = -1;
			if (broken[str[i]] == 1) i += k - 1;
		}
	}
	for (i = 0; i < len; i++){
		if (broken[str[i]] == 1){
			putchar(str[i]);
			broken[str[i]] = 2;
		}
	}
	printf("\n");
	for (i = 0; i < len; i++){
		putchar(str[i]);
		if (broken[str[i]] == 2)
			i += k - 1;
	}
	printf("\n");
	return 0;
}