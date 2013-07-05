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

#define MAX (1000001)

using namespace std;

bool
comp(float x,vector<pair<int, int> >&item,int k)
{
	vector<float> y(item.size());
	for (int i=0; i<item.size(); ++i) {
		y[i] = item[i].second - item[i].first*x;
	}
	sort(y.begin(), y.end(), greater<float>());
	float sum=0;
	for (int i=0; i<k; ++i) {
		sum += y[i];
	}
	return sum>=0;
}



float
solve(int n,int k,vector<pair<int, int> > &item)
{
	float left=0,right=MAX;
	for (int i=0; i<100; ++i) {
		float mid = (left+right)/2;
		if (comp(mid, item, k)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	return left;
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	vector<pair<int, int> > item(n);
	for (int i=0; i<n; ++i) {
		int w,v;
		scanf("%d %d",&w,&v);
		item[i] = make_pair(w, v);
	}
	float ans = solve(n,k,item);
	printf("%.2f\n",ans);
	return 0;
}