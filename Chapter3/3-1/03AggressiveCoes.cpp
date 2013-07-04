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

#define I_INF (1<<30)
#define F_INF 1e7
#define MAX 41

using namespace std;

bool
isOk(int inval,int M,vector<int> &x)
{
	int cnt=1;
	int now = x[0];
	for (int i=1; i<x.size(); ++i) {
		if (x[i]-now>=inval) {
			now = x[i];
			++cnt;
		}
	}
	return cnt>=M;
}

int
solve(int N,int M,vector<int> &x)
{
	sort(x.begin(), x.end());
	int left=0,right=I_INF;
	for (int i=0; i<100; ++i) {
		int mid = (left+right)/2;
		if (isOk(mid,M,x)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	return left;
}

int
main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	vector<int> x(N);
	for (int i=0; i<N; ++i) {
		scanf("%d",&x[i]);
	}
	int ans = solve(N,M,x);
	printf("%d\n",ans);
}