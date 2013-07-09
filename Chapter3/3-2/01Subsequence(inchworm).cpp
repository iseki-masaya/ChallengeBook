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
solve(int n,int S,vector<int> &a)
{
	int res = n + 1;
	int s=0,t=0,sum=0;
	for (;;) {
		while (t < n && sum<S) {
			sum += a[t++];
		}
		if (sum < S) {
			break;
		}
		res = min(res,t-s);
		sum -= a[s++];
	}

	return res>n ? 0 : res;
}

int
main(void) {
	int num;
	scanf("%d",&num);
	for (int loop=0; loop<num; ++loop) {
		int n,S;
		scanf("%d %d",&n,&S);

		vector<int> a(n);
		for (int i=0; i<n; ++i) {
			scanf("%d",&a[i]);
		}
		int ans = solve(n,S,a);
		printf("%d\n",ans);
	}
}