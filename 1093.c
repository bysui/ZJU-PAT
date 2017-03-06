#include <stdio.h>
#include <string.h>

char str[100001];

int main()
{
	int i, len;
	long long p, pa, pat;

	scanf("%s", str);
	len = strlen(str);

	p = pa = pat = 0;
	for (i = 0; i < len; i++){
		if (str[i] == 'P')
			p++;
		if (str[i] == 'A')
			pa += p;
		if (str[i] == 'T')
			pat += pa;
	}
	printf("%lld\n", pat % 1000000007);
	return 0;
}