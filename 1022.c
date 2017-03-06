#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

map<string, vector<string>> dlMap[5];

int main()
{
	int i, j, n, m, qid;
	string id, title, author, wordlist, publisher, year;
	string word, query;

	cin >> n;
	getchar();
	for (i = 0; i < n; i++){
		getline(cin, id);
		getline(cin, title);
		getline(cin, author);
		getline(cin, wordlist);
		getline(cin, publisher);
		getline(cin, year);

		dlMap[0][title].push_back(id);
		dlMap[1][author].push_back(id);
		dlMap[3][publisher].push_back(id);
		dlMap[4][year].push_back(id);
		
		istringstream istr(wordlist);
		while (!istr.eof()){
			istr >> word;
			dlMap[2][word].push_back(id);
		}
	}

	for (i = 0; i < 5; i++)
		for (map<string, vector<string>>::iterator it = dlMap[i].begin(); it != dlMap[i].end(); it++)
			sort(it->second.begin(), it->second.end());
	
	cin >> m;
	for (i = 0; i < m; i++){
		scanf("%d: ", &qid);
		getline(cin, query);
		printf("%d: ", qid);
		cout << query << endl;

		map<string, vector<string>>::iterator it;
		it = dlMap[qid - 1].find(query);
		if (it != dlMap[qid - 1].end()){
			vector<string> res;
			res = dlMap[qid - 1][query];
			for (j = 0; j < res.size(); j++)
				cout << res[j] << endl;
		}
		else
			cout << "Not Found" << endl;
	}
	return 0;
}