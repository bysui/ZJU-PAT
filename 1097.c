#include <cstdio>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int n, head;
int address[1000000];
int value[1000000];

int main()
{
	int i, ad, key, next, len;
	set<int> skey;
	vector<int> list1, list2;

	scanf("%d %d", &head, &n);
	for (i = 0; i < 1000000; i++)
		address[i] = -1;
	for (i = 0; i < n; i++){
		scanf("%d %d %d", &ad, &key, &next);
		address[ad] = next;
		value[ad] = key;
	}
	for (i = head; i != -1; i = address[i]){
		if (skey.find(abs(value[i])) != skey.end())
			list2.push_back(i);
		else{
			list1.push_back(i);
			skey.insert(abs(value[i]));
		}
	}
	len = list1.size();
	for (i = 0; i < len - 1; i++)
		printf("%05d %d %05d\n", list1[i], value[list1[i]], list1[i + 1]);
	printf("%05d %d -1\n", list1[i], value[list1[i]]);
	len = list2.size();
	if (len > 0){
		for (i = 0; i < len - 1; i++)
			printf("%05d %d %05d\n", list2[i], value[list2[i]], list2[i + 1]);
		printf("%05d %d -1\n", list2[i], value[list2[i]]);
	}
	
	return 0;
}