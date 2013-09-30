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

#define MAX_N 1005
int N,K;
int A[MAX_N],B[MAX_N];
int idx[MAX_N];

typedef pair<double, int> P;

double V;

bool
comp(int i,int j)
{
    return A[i] - V*B[i] > A[j] - V*B[j];
}

bool
check(double m)
{
    V = m;
    sort(idx, idx+N, comp);
    double sum = 0.0;
    for (int i=0; i < N-K; ++i) {
        sum += A[idx[i]] - V*B[idx[i]];
    }
    return sum >= 0.0;
}

void
solve()
{
    double lb = 0.0 , ub = 1.0 , mid;
    for (int i=0; i<100; ++i) {
        mid = (lb+ub)/2.0;
        if (check(mid)) {
            lb = mid;
        }
        else {
            ub = mid;
        }
    }
    printf("%d\n",(int)(100*mid + 0.5));
}

int
main()
{
    while (true) {
        scanf("%d %d",&N,&K);
        if (N == 0 && K == 0) {
            break;
        }
        for (int i=0; i<N; ++i) {
            scanf("%d",&A[i]);
        }
        for (int i=0; i<N; ++i) {
            scanf("%d",&B[i]);
            idx[i] = i;
        }
        solve();
    }
    return 0;
}