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

#define INF (1<<20)
#define MAX_N (500000+10)
#define MAX_M (500000+10)

int n,dat[2*MAX_N];

void
init(int _n)
{
	n = 1;
	while (n < _n)
		n *= 2;
	for (int i=0; i<2*n-1; ++i) {
		dat[i] = INF;
	}
}

void
update(int k,int a)
{
	k += n - 1;
	dat[k] = a;
	while (k > 0) {
		k = (k-1)/2;
		dat[k] = min(dat[k*2+1],dat[k*2+2]);
	}
}

int
query(int a,int b,int k,int l,int r)
{
	if (r <= a || b <= l) {
		return INF;
	}
	if (a <= l && r <= b) {
		return dat[k];
	}
	else {
		int vl = query(a, b, k*2+1, l, (l+r)/2 );
		int vr = query(a, b, k*2+2, (l+r)/2, r );
		return min(vl,vr);
	}
}

int N,M;
int dp[MAX_N+1];

int s[MAX_M],t[MAX_M];

void
solve()
{
	init(N+1);
	fill(dp, dp+N+1, INF);
	dp[1] = 0;
	update(1, 0);
	for (int i=0; i<M; ++i) {
		int v = min(dp[t[i]], query(s[i], t[i]+1, 0, 0, n) + 1);
		dp[t[i]] = v;
		update(t[i], v);
	}
	printf("%d\n",dp[N]);
}

int
main()
{
	scanf("%d %d",&N,&M);
	for (int i=0; i<M; ++i) {
		scanf("%d %d",&s[i],&t[i]);
	}
	solve();
}