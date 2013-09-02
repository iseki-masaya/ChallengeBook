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
#include <time.h>

#define INF (1<<26)
#define MAX_N 105

using namespace std;

int N;
int W[MAX_N];

void
solve()
{
    sort(W, W+N, greater<int>());
    double res = W[0];
    for (int i=1; i<N; ++i) {
        res = 2.0 * sqrt(W[i]*res);
    }
    printf("%.3lf\n",res);
}

int
main()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        scanf("%d",&W[i]);
    }
    solve();
    return 0;
}
