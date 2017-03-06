#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int len[4];
	int time[3];
	char str[4][62];
	const char* day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

	for (i = 0; i < 4; i++){
		scanf("%s", str[i]);
		len[i] = strlen(str[i]);
	}
	for (i = 0; i < len[0] && i < len[1]; i++){
		if (str[0][i] == str[1][i] && str[0][i] >= 'A' && str[0][i] <= 'G' ){
			time[0] = str[0][i] - 'A';
			break;
		}
	}
	for (i++; i < len[0] && i < len[1]; i++){
		if (str[0][i] == str[1][i]){
			if (str[0][i] >= '0' && str[0][i] <= '9'){
				time[1] = str[0][i] - '0';
				break;
			}
			else if (str[0][i] >= 'A' && str[0][i] <= 'N'){
				time[1] = str[0][i] - 'A' + 10;
				break;
			}
		}
	}
	for (i = 0; i < len[2] && i < len[3]; i++){
		if (str[2][i] == str[3][i] && ((str[2][i] >= 'A' && str[2][i] <= 'Z') || (str[2][i] >= 'a' && str[2][i] <= 'z'))){
			time[2] = i;
			break;
		}
	}
	printf("%s %02d:%02d\n", day[time[0]], time[1], time[2]);

	return 0;
}