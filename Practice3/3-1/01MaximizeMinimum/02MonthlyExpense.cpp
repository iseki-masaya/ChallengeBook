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

int N,M;
int D[MAX_N];

bool
b_search(int m)
{
    int cnt = 1;
    int sum = 0;
    for (int i=0; i<N; ++i) {
        if (D[i] > m) {
            return false;
        }

        sum += D[i];
        if (sum > m) {
            ++cnt;
            sum = D[i];
        }
    }
    return cnt <= M;
}

void
solve()
{
    int lb = 0 , ub = 1000000001;
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
    scanf("%d %d",&N,&M);
    for (int i=0; i<N; ++i) {
        scanf("%d",&D[i]);
    }
    solve();
}