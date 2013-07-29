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

#define INF (1<<20)

const int MAX_N = 1<<5;

int n,dat[2*MAX_N - 1];

void
init(int _n)
{
	n = _n;
//	while (n < _n) {
//		n *= 2;
//	}
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
		k = (k - 1)/2;
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
		int vl = query(a, b, k*2 + 1, l, (l + r)/2);
		int vr = query(a, b, k*2 + 2, (l + r)/2, r);
		return min(vl,vr);
	}
}

int
main()
{
	int n = 8;
	init(n);
	vector<int> sample =
	{5,3,7,9,6,4,1,2}
	;
	for (int i=0; i<sample.size(); ++i) {
		update(i, sample[i]);
	}
	int ans = query(2, 5, 0, 0, n);
	cout << ans;
}
