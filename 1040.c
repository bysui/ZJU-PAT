#include <iostream>
#include <string>
using namespace std;

bool map[1001][1001];

int main()
{
	int i, j, len, max;
	string str;

	getline(cin, str);
	len = str.length();
	max = 1;
	for (j = 0; j < len; j++){
		for (i = 0; i <= j; i++){
			if (j - i < 2)
				map[i][j] = (str[i] == str[j]);
			else
				map[i][j] = (str[i] == str[j] && map[i + 1][j - 1]);
			if (map[i][j] && max < j - i + 1)
				max = j - i + 1;
		}
	}
	printf("%d\n", max);
	return 0;
}