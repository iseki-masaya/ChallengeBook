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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>

#define INF (1<<28)
#define EPS 1e-8
#define MOD 100000000

using namespace std;

#define MAX_N 35

int ans[MAX_N];
int N;

void
solve()
{
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    ans[2] = 3;
    for (int i=4; i<34; i+=2) {
        int res = ans[i-2]*3;
        for (int j=i-4; j>0; j-=2) {
            res += ans[j]*2;
        }
        ans[i] = res + 2;
    }
}

bool
init()
{
    scanf("%d",&N);
    return N>=0;
}

int
main()
{
    solve();
    while (init()) {
        printf("%d\n",ans[N]);
    }
    return 0;
}