#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> seq;
int matrix[10000][10000];

int main()
{
	int i, j, k, index, n, half;
	int row, column;

	cin >> n;
	seq.resize(n);
	for (i = 0; i < n; i++)
		cin >> seq[i];
	sort(seq.begin(), seq.end(), greater<int>());

	half = sqrt((double)n);
	for (i = half; i > 0; i--){
		if (n % i == 0)
			break;
	}
	row = n / i;
	column = i;

	index = i = j = k = 0;
	while (k  < column / 2){
		i = j = k;
		while (j < column - k - 1)
			matrix[i][j++] = seq[index++];
		while (i < row - k - 1)
			matrix[i++][j] = seq[index++];
		while (j > k)
			matrix[i][j--] = seq[index++];
		while (i > k)
			matrix[i--][j] = seq[index++];
		k++;
	}
	if (2 * k < column){
		i = j = k;
		while (i < row - k)
			matrix[i++][j] = seq[index++];
	}

	for (i = 0; i < row; i++){
		printf("%d", matrix[i][0]);
		for (j = 1; j < column; j++)
			printf(" %d", matrix[i][j]);
		printf("\n");
	}
	return 0;
}