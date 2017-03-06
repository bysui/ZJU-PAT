#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool table[10000];
int input[10000];

bool isPrime(int m)
{
	int i, end;
	bool flag;
	
	flag = true;
	end = sqrt(m);
	for (i = 2; i <= end; i++){
		if (m % i == 0){
			flag = false;
			break;
		}
	}
	return flag;
}

int main()
{
	int i, j, size, n, pos;
	
	cin >> size >> n;
	if (size == 1)
		size = 2;
	while (!isPrime(size))
		size++;
	for (i = 0; i < n; i++)
		cin >> input[i];

	for (i = 0; i < n; i++){
		for (j = 0; j < size; j++){
			pos = (input[i] + j * j) % size;
			if (!table[pos]){
				table[pos] = true;
				break;
			}
		}
		if (j == size)
			cout << "-";
		else
			cout << pos;
		if (i == n - 1)
			cout << endl;
		else
			cout << " ";
	}
	return 0;
}