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

#define INF (1<<25)

vector<int> A,R;
int mid,ans=INF;
bool used[11];
int cnt = 0;

int
calc()
{
	int left = 0 , right = 0;
	int c = 1;
	for (int i=mid; i>=0; --i) {
		left += R[i]*c;
		c *= 10;
	}
	c = 1;
	for (int i=((int)R.size())-1; i>mid; --i) {
		right += R[i]*c;
		c *= 10;
	}
	return abs(left-right);
}

void calc_min(int n)
{
	if (n == A.size()) {
		ans = min(ans,calc());
	}

	for (int i=0; i<A.size(); ++i) {
		if (!used[i]) {
			if ( A[i]==0 && (n==0||n==mid+1) && A.size()!=2 ) {
				continue;
			}
			used[i] = true;
			R[n] = A[i];
			calc_min(n+1);
			used[i] = false;
		}
	}
}

void
solve()
{
	R.resize(A.size());
	mid = -1 + (int)A.size()/2;
	calc_min(0);
	printf("%d\n",cnt);
}

int
main()
{
	int num;
	scanf("%d\n",&num);
	for (int i=0; i<num; ++i) {
		A.clear();
		memset(used, false, sizeof(used));
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
