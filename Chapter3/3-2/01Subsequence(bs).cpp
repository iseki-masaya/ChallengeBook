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
	vector<int> sum(n+1,0);
	for (int i=0; i<n; ++i) {
		sum[i+1] = sum[i] + a[i];
	}
	if (sum[n]<S) {
		return 0;
	}

	int res = n;
	for (int s=0; sum[s]+S<=sum[n]; ++s) {
		vector<int>::iterator s_it = sum.begin();
		advance(s_it, s);
		int t = static_cast<int>(distance(sum.begin(),lower_bound(s_it, sum.end(), sum[s]+S)));
		res = min(res,t-s);
	}
	return res;
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