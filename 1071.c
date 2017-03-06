#include <cstdio>
#include <string>
#include <map>
using namespace std;

#define MAXLEN 1048576 

char str[MAXLEN];

int main()
{
	map<string, int> words;
	char ch;
	string word;
	int index, count;

	index = 0;
	while ((ch = getchar()) != '\n'){
		if (isalnum(ch))
			str[index++] = tolower(ch);
		else{
			if (index > 0){
				str[index] = '\0';
				words[str]++;
				index = 0;
			}
		}
	}
	if (index > 0){
		str[index] = '\0';
		words[str]++;
		index = 0;
	}
	word = words.begin()->first;
	count = words.begin()->second;
	for (map<string, int>::iterator it = words.begin(); it != words.end(); it++){
		if (it->second > count){
			word = it->first;
			count = it->second;
		}
	}
	printf("%s %d\n", word.c_str(), count);
	return 0;
}

