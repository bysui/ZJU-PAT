#include <cstdio>
#include <stack>
using namespace std;

#define MAXLEN 400
#define MAXSIZE 400

int bucket[MAXLEN][MAXSIZE];
int bcount[MAXLEN];

int getmid(int size)
{
	int i, j, mid, cnt;

	mid = (size + 1) / 2;
	cnt = 0;
	for (i = 0; i < MAXLEN; i++){
		if (cnt + bcount[i] >= mid)
			break;
		else
			cnt += bcount[i];
	}
	for (j = 0; j < MAXSIZE; j++){
		cnt += bucket[i][j];
		if (cnt >= mid)
			break;
	}
	return i * MAXSIZE + j;
}

int main()
{
	int i, n, val;
	char op[12];
	stack<int> stk;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%s", op);
		switch (op[1]){
		case 'u':
			scanf("%d", &val);
			stk.push(val);
			val--;
			bucket[val / MAXLEN][val % MAXSIZE]++;
			bcount[val / MAXLEN]++;
			break;
		case 'o':
			if (stk.empty()){
				printf("Invalid\n");
				break;
			}
			val = stk.top();
			stk.pop();
			printf("%d\n", val);
			val--;
			bucket[val / MAXLEN][val % MAXSIZE]--;
			bcount[val / MAXLEN]--;
			break;
		case 'e':
			if (stk.empty()){
				printf("Invalid\n");
				break;
			}
			val = getmid(stk.size()) + 1;
			printf("%d\n", val);
			break;
		default:
			printf("Invalid\n");
		}
	}

	return 0;
}
