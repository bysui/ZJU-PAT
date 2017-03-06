#include <stdio.h>

int main()
{
	int i, j, m, n, color, max, cnt;

	scanf("%d %d", &m, &n);
	cnt = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			scanf("%d", &color);
			if (cnt == 0){
				max = color;
				cnt++;
			}
			else{
				if (color == max)
					cnt++;
				else
					cnt--;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}