#include <cstdio>
using namespace std;

int main()
{
	int i, n;
	double val, sum;
	
	scanf("%d", &n);;
	sum = 0;
	for (i = 0; i < n; i++){
		scanf("%lf", &val);
		sum += 1.0 * (n - i) * (i + 1) * val;
	}
	printf("%.2f\n", sum);
	return 0;
}