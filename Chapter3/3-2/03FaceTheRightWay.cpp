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
calc(int n,int k,vector<int> &dir)
{
	vector<int> f(n,0);
	int res = 0;
	int sum = 0;
	for (int i=0; i+k<=n; ++i) {
		if ((dir[i] + sum)%2 != 0) {
			++res;
			f[i] = 1;
		}
		sum += f[i];
		if (i-k+1 >= 0) {
			sum -= f[i-k+1];
		}
	}

	for (int i=n-k+1; i<n; ++i) {
		if ((dir[i] + sum)%2 != 0) {
			return -1;
		}
		if (i-k+1>=0) {
			sum -= f[i-k+1];
		}
	}

	return res;
}

void
solve(int n,vector<int> &dir)
{
	int K=1,M=n;
	for (int k=1; k<=n; ++k) {
		int m = calc(n,k,dir);
		if (m>=0 && M > m) {
			M = m;
			K = k;
		}
	}
	printf("%d %d\n",K,M);
}

int
main(void) {
	int n;
	scanf("%d",&n);
	char c;
	vector<int> dir(n);
	for (int i=0; i<n; ++i) {
		cin >> c;
		if (c == 'B') {
			dir[i] = 1;
		}
		else {
			dir[i] = 0;
		}
	}
	solve(n,dir);
}