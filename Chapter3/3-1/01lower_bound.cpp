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

#define INF (1<<20)
#define MAX 101

using namespace std;

int
solve(int n,vector<int> &a,int k)
{
	int left = 0,right = n,mid;
	while (right-left > 1) {
		mid = (right+left)/2;
		if (a[mid] >= k) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	return right;
}

int
main()
{
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	for (int i=0; i<n; ++i) {
		scanf("%d",&a[i]);
	}
	int k;
	scanf("%d",&k);
	int ans = solve(n,a,k);
	printf("%d",ans);
}