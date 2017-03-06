#include <stdio.h>
#include <string.h>

typedef struct{
	char name[11];
	char password[11];
	int change;
}Account;

Account list[1000];

int isChange(char *password)
{
	int i, len, flag;

	len = strlen(password);
	flag = 0;
	for (i = 0; i < len; i++){
		switch (password[i]){
		case '1':
			password[i] = '@';
			flag = 1;
			break;
		case '0':
			password[i] = '%';
			flag = 1;
			break;
		case 'l':
			password[i] = 'L';
			flag = 1;
			break;
		case 'O':
			password[i] = 'o';
			flag = 1;
			break;
		}
	}
	return flag;
}

int main()
{
	int i, n, cnt;

	scanf("%d", &n);
	cnt = 0;
	for (i = 0; i < n; i++){
		scanf("%s %s", list[i].name, list[i].password);
		if (isChange(list[i].password)){
			list[i].change = 1;
			cnt++;
		}
		else
			list[i].change = 0;
	}
	if (cnt == 0){
		if (n == 1)
			printf("There is 1 account and no account is modified\n");
		else
			printf("There are %d accounts and no account is modified\n", n);
	}
	else{
		printf("%d\n", cnt);
		for (i = 0; i < n; i++){
			if (list[i].change)
				printf("%s %s\n", list[i].name, list[i].password);
		}
	}
	return 0;
}