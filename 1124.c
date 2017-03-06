#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int m, n, s;
vector<string> nlist;
set<string> winner;

int main()
{
	int i;
	
	cin >> m >> n >> s;
	nlist.resize(m + 1);
	for (i = 1; i <= m; i++)
		cin >> nlist[i];
	i = s;
	while (i <= m){
		if (winner.find(nlist[i]) == winner.end()){
			cout << nlist[i] << endl;
			winner.insert(nlist[i]);
			i += n;
		}
		else
			i++;
	}
	if (winner.size() == 0)
		cout << "Keep going..." << endl;
	return 0;
}