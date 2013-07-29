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

const int MAX_N = 1<<23;

int bit[MAX_N] = {0},n;

int
sum(int i)
{
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void
add(int i, int x)
{
	while (i <= n) {
		bit[i] += x;
		i += i & -i;
	}
}

void
solve(vector<int> a)
{
	long long ans = 0;
	for (int j=0; j<n; ++j) {
		ans += j - sum(a[j]);
		add(a[j], 1);
	}
	printf("%lld\n",ans);
}

int main()
{
	scanf("%d",&n);
	vector<int> a(n);
	for (int i=0; i<n; ++i) {
		scanf("%d",&a[i]);
	}
	solve(a);
}
