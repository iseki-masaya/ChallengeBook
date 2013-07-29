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

#define MAX_N 100003
#define MAX_M 5003

const int B = 1000;

int N,M;
int A[MAX_N];
int I[MAX_M],J[MAX_M],K[MAX_M];
int nums[MAX_N];
vector<int> bucket[MAX_N/B];

void
solve()
{
	for (int i=0; i<N; ++i) {
		bucket[i/B].push_back(A[i]);
		nums[i] = A[i];
	}
	sort(nums, nums + N);
	for (int i=0; i < N/B; ++i) {
		sort(bucket[i].begin(), bucket[i].end());
	}
	for (int i=0; i<M; ++i) {
		int l = I[i] , r = J[i]+1 , k = K[i];
		int lb = -1 , ub = N-1;
		while (ub - lb > 1) {
			int md = (ub+lb)/2;
			int x = nums[md];
			int tl = l , tr = r , c = 0;

			while (tl < tr && tl%B != 0) if (A[tl++] <= x) ++c;
			while (tl < tr && tr%B != 0) if (A[--tr] <= x) ++c;

			while (tl < tr) {
				int b = tl/B;
				c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
				tl += B;
			}
			if (c >= k) {
				ub = md;
			}
			else {
				lb = md;
			}
		}

		printf("%d\n",nums[ub]);
	}
}

int
main()
{
	scanf("%d %d",&N,&M);
	for (int i=0; i<N; ++i) {
		scanf("%d",&A[i]);
	}
	for (int i=0; i<M; ++i) {
		scanf("%d %d %d",&I[i],&J[i],&K[i]);
		--I[i],--J[i];
	}
	solve();
}