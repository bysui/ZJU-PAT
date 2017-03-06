#include <stdio.h>
#include <string.h>

int main()
{
	int i, n;
	int h, m, s;
	int in, out;
	char id[16];
	char unlock[16], lock[16];

	in = 24 * 60 * 60;
	out = -1;

	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%s", id);
		scanf("%d:%d:%d", &h, &m, &s);
		if (h * 3600 + m * 60 + s < in){
			in = h * 3600 + m * 60 + s;
			strcpy(unlock, id);
		}
		scanf("%d:%d:%d", &h, &m, &s);
		if (h * 3600 + m * 60 + s > out){
			out = h * 3600 + m * 60 + s;
			strcpy(lock, id);
		}		
	}

	printf("%s %s\n", unlock, lock);
	return 0;
}