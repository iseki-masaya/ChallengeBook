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

using namespace std;

#define MAX_R 11
#define MAX_C 10005

int R,C;
vector<vector<int> > m(MAX_R,vector<int>(MAX_C));

void
flip(vector<vector<int> > &t,int r)
{
    for (int c=0; c<C; ++c) {
        t[r][c] = t[r][c]^1;
    }
}

int
count(vector<vector<int> > &t)
{
    int res = 0;
    int f_cnt,t_cnt;
    for (int c=0; c<C; ++c) {
        f_cnt=t_cnt=0;
        for (int r=0; r<R; ++r) {
            if (t[r][c]) {
                ++t_cnt;
            }
            else {
                ++f_cnt;
            }
        }
        res += max(f_cnt,t_cnt);
    }
    return res;
}

void
solve()
{
    int lim = (1<<R);
    int res = 0;
    for (int i=0; i<lim; ++i) {
        vector<vector<int> > t(m);
        for (int j=0; j<R; ++j) {
            if ((i>>j)&1) {
                flip(t,j);
            }
        }
        res = max(res,count(t));
    }
    printf("%d\n",res);
}

int
main()
{
    while (true) {
        scanf("%d %d",&R,&C);
        if (R==0 && C==0) break;
        for (int r=0; r<R; ++r) {
            for (int c=0; c<C; ++c) {
                scanf("%d",&m[r][c]);
            }
        }
        solve();
    }
    return 0;
}