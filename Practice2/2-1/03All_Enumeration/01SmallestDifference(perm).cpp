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
int mid;
#define INF (1<<25)

bool
next_perm()
{
	int i = (int)A.size()-2;
	while (A[i] > A[i+1]) --i;
	if (i==0) return false;

	int mnp = i+1;
	for (int j=i+1; j<A.size(); ++j) {
		if (A[i]<A[j] && A[mnp]>A[j]) {
			mnp = j;
		}
	}
	swap(A[i], A[mnp]);
	int left = i+1 , right = (int)A.size()-1;
	while (left < right) {
		swap(A[left], A[right]);
		++left , --right;
	}
	return true;
}

int
calc()
{
	int left = 0 , right = 0;
	int c = 1;
	for (int i=mid; i>0; --i) {
		left += A[i]*c;
		c *= 10;
	}
	c = 1;
	for (int i=((int)A.size())-1; i>mid; --i) {
		right += A[i]*c;
		c *= 10;
	}
	return abs(left-right);
}

void
solve()
{
	int ans = INF;
	mid = ((int)A.size()-1)/2;
	do {
		if ( (A[1]!=0 && A[mid+1]!=0) || A.size()==3) {
			ans = min(ans,calc());
		}
	} while (next_perm());
	printf("%d\n",ans);
}

int
main()
{
	int num;
	scanf("%d\n",&num);
	for (int i=0; i<num; ++i) {
		A.clear();
		A.push_back(-1);
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
