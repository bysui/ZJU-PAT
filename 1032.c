#include <stdio.h>
#include <memory.h>

int node[100000];
int link[100000];

int main()
{
	int s1, s2, i, n;
	int ad, next;
	char ch;

	scanf("%d %d %d", &s1, &s2, &n);
	for (i = 0; i < n; i++){
		scanf("%d %c %d", &ad, &ch, &next);
		node[ad] = next;
	}
	while (s1 != -1){
		link[s1] = 1;
		s1 = node[s1];
	}
	while (s2 != -1){
		if (link[s2] == 1){
			printf("%05d\n", s2);
			return 0;
		}
		else
			s2 = node[s2];
	}
	printf("-1\n");
	return 0;
}