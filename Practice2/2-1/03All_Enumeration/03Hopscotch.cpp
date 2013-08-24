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

const int X = 5;
const int Y = 5;

int m[Y][X];
set<string> s;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

void
dfs(int x,int y,string &d)
{
    if (d.size()==6) {
        s.insert(d);
        return;
    }

    for (int i=0; i<4; ++i) {
        int cx = x+dx[i] , cy = y+dy[i];
        if (0 <= cx && cx < X && 0 <= cy && cy < Y) {
            d += (char)m[cy][cx]+'0';
            dfs(cx, cy, d);
            d.resize(d.size()-1);
        }
    }
}

void
solve()
{
    for (int y=0; y<Y; ++y) {
        for (int x=0; x<X; ++x) {
            string d = "";
            dfs(x,y,d);
        }
    }
    printf("%d\n",(int)s.size());
}

int
main()
{
    for (int y=0; y<Y; ++y) {
        for (int x=0; x<X; ++x) {
            scanf("%d",&m[y][x]);
        }
    }
    solve();
}