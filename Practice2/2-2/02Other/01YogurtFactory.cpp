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

#define MAX_N 10005
#define INF (1<<26)

using namespace std;

int N,S;
int C[MAX_N],Y[MAX_N];

void
solve()
{
    int mn = INF;
    long long res = 0;
    for (int i=0; i<N; ++i) {
        mn = min(mn+S,C[i]);
        res += mn*Y[i];
    }
    printf("%lld\n",res);
}

int
main()
{
    scanf("%d %d",&N,&S);
    for (int i=0; i<N; ++i) {
        scanf("%d %d",&C[i],&Y[i]);
    }
    solve();
}