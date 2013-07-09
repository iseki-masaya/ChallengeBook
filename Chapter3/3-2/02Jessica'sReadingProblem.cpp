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

#define MAX_V (10000001)
#define MAX_N (100001)
#define MOD 1000000007

using namespace std;

int
solve(int P,vector<int> &a)
{
	set<int> all;
	for (int i=0; i<P; ++i) {
		all.insert(a[i]);
	}
	int n = static_cast<int>(all.size());

	map<int,int> count;
	int s=0,t=0,num=0;
	int res = P;
	for (;;) {
		while (t<P && num < n) {
			if (count[a[t++]]++ == 0) {
				++num;
			}
		}
		if (num < n) {
			break;
		}
		res = min(res,t-s);
		if (--count[a[s++]]==0) {
			--num;
		}
	}
	return res;
}

int
main(void) {
	int n;
	scanf("%d",&n);

	vector<int> a(n);
	for (int i=0; i<n; ++i) {
		scanf("%d",&a[i]);
	}
	int ans = solve(n,a);
	printf("%d\n",ans);

}