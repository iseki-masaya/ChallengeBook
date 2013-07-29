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

#define MAX_N	100003
#define MAX_Q	100003

const int DAT_SIZE = (1<<18)-1;

int N,Q;
char T[MAX_Q];

long long data[DAT_SIZE]={0},datb[DAT_SIZE]={0};

void
add(int a,int b,int x,int k,int l,int r)
{
	if (a <= l && r <= b) {
		data[k] += x;
	}
	else if (l < b && a < r) {
		datb[k] += ( min(b,r) - max(a,l) )*x;
		add(a, b, x, k*2 + 1, l, (l+r)/2);
		add(a, b, x, k*2 + 2, (l+r)/2, r);
	}
}

long long
sum(int a,int b,int k,int l,int r)
{
	if (b <= l || r <= a) {
		return 0;
	}
	else if (a <= l && r <= b) {
		return (data[k]*(r-l) + datb[k]);
	}
	else {
		long long res = ( min(r,b) - max(l,a) )*data[k];
		res += sum(a, b, k*2 + 1, l, (l+r)/2);
		res += sum(a, b, k*2 + 2, (l+r)/2, r);
		return res;
	}
}

int
main()
{
	int work,l,r,x;
	scanf("%d %d",&N,&Q);
	for (int i=0; i<N; ++i) {
		scanf("%d",&work);
		add(i, i+1, work, 0, 0, N);
	}
	for (int i=0; i<Q; ++i) {
		scanf("%*c%c",&T[i]);
		if (T[i] == 'C') {
			scanf("%d %d %d",&l,&r,&x);
			add(l-1, r, x, 0, 0, N);
		}
		else {
			scanf("%d %d",&l,&r);
			printf("%lld\n",sum(l-1, r, 0, 0, N));
		}
	}
}

