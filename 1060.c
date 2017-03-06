#include <stdio.h>
#include <string.h>

int n;
char num[2][102];
char digit[2][101];
int eg[2];

void change(char *str, int idot, int nozero, int num, int id)
{
	int i, j, len;

	len = strlen(str);
	j = 0;
	for (i = nozero; j < num && i < len; i++){
		if (str[i] != '.'){
			digit[id][j] = str[i];
			j++;
		}
	}
	while (j < num){
		digit[id][j] = '0';
		j++;
	}
	digit[id][j] = '\0';
}

int cal(char *str, int idot, int nozero)
{
	int i, len;

	len = strlen(str);

	if (nozero < idot)
		return idot - nozero;
	else
		return idot - nozero + 1;
}

int findNoZero(char *str)
{
	int i, len;

	len = strlen(str);
	for (i = 0; i < len; i++){
		if (str[i] != '0'&&str[i] != '.')
			break;
	}
	if (i == len)
		return -1;
	else
		return i;
}

void print(int id, int iszero)
{
	int i;

	if (iszero){
		printf(" 0.");
		for (i = 0; i < n; i++)
			printf("0");
		printf("*10^0");
	}
	else
		printf(" 0.%s*10^%d", digit[id], eg[id]);
}

int main()
{
	int i, nozero, idot;
	int iszero[2];
	char *dot;

	scanf("%d %s %s", &n, num[0], num[1]);
	for (i = 0; i < 2; i++){
		dot = strchr(num[i], '.');
		if (dot == NULL)
			idot = strlen(num[i]);
		else
			idot = dot - num[i];

		nozero = findNoZero(num[i]);
		if (nozero != -1){
			change(num[i], idot, nozero, n, i);
			eg[i] = cal(num[i], idot, nozero);
			iszero[i] = 0;
		}
		else
			iszero[i] = 1;
	}
	if (!strcmp(digit[0], digit[1]) && eg[0] == eg[1]){
		printf("YES");
		print(0, iszero[0]);
	}
	else{
		printf("NO");
		print(0, iszero[0]);
		print(1, iszero[1]);
	}
	return 0;
}