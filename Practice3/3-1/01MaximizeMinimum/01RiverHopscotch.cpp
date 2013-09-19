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

#define MAX_N 50005

int N,M,L;
int R[MAX_N];

bool
b_search(int interval)
{
    int cnt = 0;
    int prv = 0;
    for (int i=1; i<N; ++i) {
        if (R[i] - prv < interval) {
            ++cnt;
            continue;
        }
        prv = R[i];
    }
    return cnt <= M;
}

void
solve()
{
    sort(R, R+N);
    int lb = 0 , ub = 1000000001;
    while (ub - lb > 1) {
        int mid = (ub+lb)/2;
        if (b_search(mid)) {
            lb = mid;
        }
        else {
            ub = mid;
        }
    }
    printf("%d\n",lb);
}

int
main()
{
    scanf("%d %d %d",&L,&N,&M);
    R[0] = 0;
    for (int i=1; i<=N; ++i) {
        scanf("%d",&R[i]);
    }
    R[N+1] = L;
    N += 2;
    solve();
}