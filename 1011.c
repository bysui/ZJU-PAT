#include <stdio.h>

int main()
{
	char ch[3];
	double w, t, l, c, s;
	int i;
	
	s = 1;
	for (i = 0; i < 3; i++){
		scanf("%lf%lf%lf", &w, &t, &l);
		if (w > t && w > l){
			c = w;
			ch[i] = 'W';
		}
		if (t > w && t > l){
			c = t;
			ch[i] = 'T';
		}
		if (l > w && l > t){
			c = l;
			ch[i] = 'L';
		}
		s = s * c;
	}
	s = (s*0.65 - 1) * 2;
	for (i = 0; i < 3; i++)
		printf("%c ", ch[i]);
	printf("%.2f\n", s);
	return 0;
}