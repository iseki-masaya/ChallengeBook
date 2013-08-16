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
#include <time.h>

using namespace std;

vector<int> A;

#define INF (1<<25)

int
calc()
{
	int left = 0 , right = 0;
	int c = 1;
	int mid = ((int)A.size())/2;
	for (int i=mid-1; i>=0; --i) {
		left += A[i]*c;
		c *= 10;
	}
	c = 1;
	for (int i=((int)A.size())-1; i>=mid; --i) {
		right += A[i]*c;
		c *= 10;
	}
	return abs(left-right);
}

void
solve()
{
	int ans = INF;
	do {
		if ((A[0]!=0 && A[A.size()/2]!=0) || A.size()==2) {
			ans = min(ans,calc());
		}
	} while (next_permutation(A.begin(), A.end()));
	printf("%d\n",ans);
}

int
main()
{
	int num;
	scanf("%d\n",&num);
	for (int i=0; i<num; ++i) {
		A.clear();
		string s;
		getline(cin, s);
		for (int i=0; i<s.size(); ++i) {
			if ('0'<=s[i] && s[i]<='9') {
				A.push_back(s[i]-'0');
			}
		}
		solve();
	}
	return 0;
}
