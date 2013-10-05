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

const int Y = 5 , X = 6;
const int dx[] = {0,1,-1,0,0} , dy[] = {0,0,0,1,-1};

int m[Y][X],a[Y][X],ans[Y][X];




void
f(int y,int x)
{
    ++ans[y][x];
    for (int i=0; i<5; ++i) {
        int cx = dx[i] + x;
        int cy = dy[i] + y;
        if (0 <= cx && cx < X && 0 <= cy && cy < Y) {
            ++a[cy][cx];
        }
    }
}

void
solve()
{
    int lim = (1<<X);
    for (int i=0; i<lim; ++i) {
        memset(a, 0, sizeof(a));
        memset(ans, 0, sizeof(ans));
        for (int x=0; x<X; ++x) {
            if ((i>>x)&1) {
                f(0,x);
            }
        }
        for (int y=1; y<Y; ++y) {
            for (int x=0; x<X; ++x) {
                if ( (m[y-1][x] + a[y-1][x])&1 ) {
                    f(y,x);
                }
            }
        }
        bool is_ok = true;
        for (int y=0; y<Y && is_ok; ++y) {
            for (int x=0; x<X && is_ok; ++x) {
                if ( (m[y][x] + a[y][x])&1 ) {
                    is_ok = false;
                }
            }
        }
        if (is_ok) {
            break;
        }
    }
    for (int y=0; y<Y; ++y) {
        for (int x=0; x<X; ++x) {
            printf("%d%c",ans[y][x],x==X-1?'\n':' ');
        }
    }
}

int
main()
{
    int num;
    scanf("%d",&num);
    for (int i=0; i<num; ++i) {
        for (int y=0; y<Y; ++y) {
            for (int x=0; x<X; ++x) {
                scanf("%d",&m[y][x]);
            }
        }
        printf("PUZZLE #%d\n",i+1);
        solve();
    }
}