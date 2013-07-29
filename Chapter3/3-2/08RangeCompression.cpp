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

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int
compress(vector<int> &x1,vector<int> &x2,int w)
{
	vector<int> xs;

	for (int i=0; i<x1.size(); ++i) {
		for (int d=-1; d<=1; ++d) {
			int tx1 = x1[i] + d, tx2 = x2[i] +d;
			if (1 <= tx1 && tx1 <= w) {
				xs.push_back(tx1);
			}
			if (1 <= tx2 && tx2 <= w) {
				xs.push_back(tx2);
			}
		}
	}

	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());

	for (int i=0; i<x1.size(); ++i) {
		x1[i] = static_cast<int>(find(xs.begin(), xs.end(), x1[i]) - xs.begin());
		x2[i] = static_cast<int>(find(xs.begin(), xs.end(), x2[i]) - xs.begin());
	}

	return (int)xs.size();
}

void
solve(int w,int h,int n,vector<vector<int> >a)
{
	vector<int> x1(a[0]),x2(a[1]),y1(a[2]),y2(a[3]);
	w = compress(x1, x2, w);
	h = compress(y1, y2, h);

	vector<vector<int> > fld(6*n,vector<int>(6*n,false));
	for (int i=0; i<n; ++i) {
		for (int y=y1[i]; y <= y2[i]; ++y) {
			for (int x=x1[i]; x <= x2[i]; ++x) {
				fld[y][x] = true;
			}
		}
	}

	int ans = 0;
	for (int y=0; y<h; ++y) {
		for (int x=0; x <w; ++x) {
			if (fld[y][x]) {
				continue;
			}
			++ans;
			queue<pair<int, int> > que;
			que.push(make_pair(x, y));
			while (!que.empty()) {
				int sx = que.front().first, sy = que.front().second;
				que.pop();

				for (int i=0; i<4; ++i) {
					int tx = sx + dx[i], ty = sy + dy[i];
					if (tx < 0 || w<=tx || ty < 0 || h <= ty ) {
						continue;
					}
					if (fld[ty][tx]) {
						continue;
					}
					que.push(make_pair(tx, ty));
					fld[ty][tx] = true;
				}
			}
		}
	}

	printf("%d\n",ans);
}

int
main()
{
	int w,h,n;
	scanf("%d %d %d",&w,&h,&n);
	vector<vector<int> > a(4,vector<int>(n,0));
	for (int i=0; i<a.size(); ++i) {
		for (int j=0; j<n; ++j) {
			scanf("%d",&a[i][j]);
		}
	}
	solve(w,h,n,a);
}
