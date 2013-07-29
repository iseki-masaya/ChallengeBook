#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;

int d[4] = {-1,1,4,-4};

inline
bool
isIn(int n)
{
	return n<8&&n>=0;
}

int main()
{
	string s;
	map<string, int> used;
	queue<string> q;
	q.push("01234567");
	used["01234567"] = 0;

	while (!q.empty()) {
		s = q.front() , q.pop();
		int ps = (int)s.find("0");
		for (int i=0; i<4; ++i) {
			if (ps%4==0 && i==0) continue;
			if (ps%4==3 && i==1) continue;
			string work = s;
			int pd = ps + d[i];
			if (!isIn(pd)) continue;
			swap(work[ps], work[pd]);
			if (used.find(work) != used.end()) continue;
			q.push(work);
			used[work] = used[s] + 1;
		}
	}

	while (getline(cin, s)) {
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
		cout << used[s] << endl;
	}
	return 0;
}