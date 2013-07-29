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

long long bit0[MAX_N],bit1[MAX_N];

long long
sum(long long *b,int i)
{
	long long s = 0;
	while (i > 0) {
		s += b[i];
		i -= i & -i;
	}
	return s;
}

void
add(long long *b,int i,int v)
{
	while (i <= N) {
		b[i] += v;
		i += i & -i;
	}
}

int
main()
{
	int work,l,r,x;
	scanf("%d %d",&N,&Q);
	for (int i=1; i<=N; ++i) {
		scanf("%d",&work);
		add(bit0, i, work);
	}

	for (int i=0; i<Q; ++i) {
		scanf("%*c%c",&T[i]);
		if (T[i] == 'C') {
			scanf("%d %d %d",&l,&r,&x);
			add(bit0, l, -x*(l-1));
			add(bit1, l, x);
			add(bit0, r+1, x*r);
			add(bit1, r+1, -x);
		}
		else {
			scanf("%d %d",&l,&r);
			long long res = 0;
			res += sum(bit0, r) + sum(bit1, r)*r;
			res -= sum(bit0, l-1) + sum(bit1, l-1)*(l-1);
			printf("%lld\n",res);
		}
	}
}

