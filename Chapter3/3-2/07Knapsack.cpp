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

#define INF (1<<30)

bool
comp(const pair<long long, long long> &lhs,const pair<long long, long long> &rhs)
{
	return lhs.first < rhs.first;
}

void
solve(int n,vector<int> &W,vector<int> &V,long long weight)
{
	int n2 = n/2;
	vector<pair<long long,long long> > ps(1<<n2);
	for (int i=0; i < 1<<n2; ++i) {
		long long sw = 0,sv = 0;
		for (int j=0; j<n2; ++j) {
			if (i>>j & 1) {
				sw += W[j];
				sv += V[j];
			}
		}
		ps[i] = make_pair(sw, sv);
	}

	sort(ps.begin(), ps.end());
	int m = 1;
	for (int i=1; i < 1<<n2; ++i) {
		if (ps[m-1].second < ps[i].second) {
			ps[m++] = ps[i];
		}
	}

	long long ansV = 0;
	long long ansW = 0;
	for (int i=0; i < 1<<(n-n2); ++i) {
		long long sw = 0,sv = 0;
		for (int j=0; j<n-n2; ++j) {
			if (i >> j & 1) {
				sw += W[n2+j];
				sv += V[n2+j];
			}
		}
		if (sw <= weight) {
			pair<int, int> res = *(lower_bound(ps.begin(),ps.begin()+m , make_pair(weight-sw+1, INF) ,comp )-1);
			if (ansV<sv+res.second) {
				ansV = sv+res.second;
				ansW = sw+res.first;
			}
		}
	}
	printf("%lld\n%lld\n",ansV,ansW);
}

int
main()
{
	int num=1;
	while (true) {
		long long weight;
		scanf("%lld",&weight);
		if (weight==0) {
			return 0;
		}
		int n;
		scanf("%d",&n);
		vector<int> W(n),V(n);
		for (int i=0; i<n; ++i) {
			int w,d;
			scanf("%d,%d",&d,&w);
			W[i] =w;
			V[i] =d;
		}
		printf("Case %d:\n",num);
		++num;
		solve(n,W,V,weight);
	}
}
