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

#define INF (1<<29)
#define EPS 1e-6

using namespace std;

#define SIZE 21

bool dir[SIZE];

void
solve()
{
    int N = SIZE;
    int res = INF;
    bool f[SIZE];
    for (int p = 0; p<=1; ++p) {
        memset(f, false, sizeof(f));
        dir[0] = p?1:0;
        int p_res = 0 , sum = 0;
        for (int i=0; i<N-1; ++i) {
            if ( (dir[i]+sum)&1 ) {
                ++p_res;
                f[i] = true;
            }
            sum += f[i]?1:0;
            if (i-2 >= 0) {
                sum -= f[i-2]?1:0;
            }
        }
        if ( !((dir[N-1]+sum)&1) ) {
            res = min(res,p_res);
        }
    }
    printf("%d\n",res);
}

int
main()
{
    int d;
    memset(dir, false, sizeof(dir));
    for (int i=1; i<21; ++i) {
        scanf("%d",&d);
        dir[i] = (bool)d;
    }
    solve();
}