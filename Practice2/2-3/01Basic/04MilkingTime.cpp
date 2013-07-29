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

int N,M,R;

struct milk {
  int start,end,efficient;
};

bool
comp(const milk &lhs,const milk &rhs)
{
	return lhs.end < rhs.end;
}

void
solve(vector<milk> &ms)
{
	sort(ms.begin(), ms.end(), comp);
	map<int, long long> dp;
	for (int i=0; i<M; ++i) {
		long long mx = dp.count(ms[i].end)==1?dp[ms[i].end]:0;
		mx = max(mx,(long long)ms[i].efficient);
		map<int , long long>::iterator start = dp.begin(), end = dp.end();
		for (; start != end; ++start) {
			if ((*start).first + R <= ms[i].start) {
				mx = max(mx,(*start).second + ms[i].efficient);
			}
		}
		dp[ms[i].end] = mx;
	}
	long long ans = 0;
	for (map<int,long long>::iterator s=dp.begin(),e=dp.end(); s != e; ++s) {
		ans = max(ans,(*s).second);
	}
	printf("%lld\n",ans);
}

int
main()
{
	scanf("%d %d %d",&N,&M,&R);
	milk m;
	vector<milk> ms(M);
	for (int i=0; i<M; ++i) {
		scanf("%d %d %d",&m.start,&m.end,&m.efficient);
		ms[i] = m;
	}
	solve(ms);
}

