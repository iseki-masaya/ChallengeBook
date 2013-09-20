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
#include <numeric>

#define L_INF (1)
#define INF (1<<29)
#define EPS 1e-6

using namespace std;

#define MAX_N 100005

int N,K;
int A[MAX_N];

bool
b_search(int m)
{
    long long cnt = 0;
    for (int i=0; i<N; ++i) {
        if (A[i] <= m) {
            break;
        }
        cnt += (A[i]-m-1)/(K-1) + 1;
    }
    return cnt <= m;
}

void
solve()
{
    sort(A, A+N,greater<int>());
    if (K == 1) {
        printf("%d\n",A[0]);
        return;
    }
    int lb = 0 , ub = 1000000005;
    while (ub - lb > 1) {
        int mid = (ub + lb)/2;
        if (b_search(mid)) {
            ub = mid;
        }
        else {
            lb = mid;
        }
    }
    printf("%d\n",ub);
}

int
main()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        scanf("%d",&A[i]);
    }
    scanf("%d",&K);
    solve();
}