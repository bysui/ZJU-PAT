#include <stdio.h>
#include <string.h>

char s1[81], s2[80];
int letter[37];

void print(char ch)
{
	int id;

	if (ch >= 'a'&&ch <= 'z'){
		id = ch - 'a';
		ch = ch - 'a' + 'A';
	}
	else if (ch >= 'A'&&ch <= 'Z')
		id = ch - 'A';
	else if (ch >= '0'&&ch <= '9')
		id = ch - '0' + 26;
	else if (ch == '_')
		id = 36;
	if (letter[id] == 0){
		printf("%c", ch);
		letter[id] = 1;
	}
}

int main()
{
	int i, j, ch, len1, len2;
	
	
	scanf("%s", s1);
	scanf("%s", s2);
	len1 = strlen(s1);
	len2 = strlen(s2);

	i = j = 0;
	while(j < len2){
		while (s1[i] != s2[j]){
			print(s1[i]);
			i++;
		}
		i++;
		j++;
	}
	while (i < len1){
		print(s1[i]);
		i++;
	}
	return 0;
}