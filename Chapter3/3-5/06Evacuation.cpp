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

#define MAX_V 10005

int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void
add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

bool
dfs(int v)
{
    used[v] = true;
    for (int i=0; i<G[v].size(); ++i) {
        int u = G[v][i] , w = match[u];
        if (w < 0 || (!used[w]&&dfs(w)) ) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

#define MAX_X 15
#define MAX_Y 15

const int dx[4] = {-1,0,0,1} , dy[4] = {0,-1,1,0};

int X,Y;
vector<string> field(MAX_Y);

vector<int> dX,dY;
vector<int> pX,pY;
int dist[MAX_X][MAX_Y][MAX_X][MAX_Y];

void
bfs(int x,int y,int d[MAX_X][MAX_Y])
{
    queue<int> qx,qy;
    d[x][y] = 0;
    qx.push(x);
    qy.push(y);
    while (!qx.empty()) {
        x = qx.front() , qx.pop();
        y = qy.front() , qy.pop();
        for (int k=0; k<4; ++k) {
            int x2 = x+dx[k] , y2 = y+dy[k];
            if (0 <= x2 && x2 < X && 0 <= y2 && y2 < Y && field[y2][x2] == '.' && d[x2][y2] < 0) {
                d[x2][y2] = d[x][y] + 1;
                qx.push(x2);
                qy.push(y2);
            }
        }
    }
}

void
solve()
{
    int n = X*Y;
    dX.clear() , dY.clear();
    pX.clear() , pY.clear();
    memset(dist, -1, sizeof(dist));

    for (int x = 0; x < X; ++x) {
        for (int y = 0; y < Y; ++y) {
            if (field[y][x] == 'D') {
                dX.push_back(x);
                dY.push_back(y);
                bfs(x, y, dist[x][y]);
            }
            else if (field[y][x] == '.') {
                pX.push_back(x);
                pY.push_back(y);
            }
        }
    }

    int d = (int)dX.size() , p = (int)pX.size();
    for (int i=0; i<=n*d+p; ++i)
        G[i].clear();
    for (int i=0; i<d; ++i) {
        for (int j=0; j<p; ++j) {
            if (dist[dX[i]][dY[i]][pX[j]][pY[j]] >= 0) {
                for (int k = dist[dX[i]][dY[i]][pX[j]][pY[j]]; k<=n; ++k) {
                    add_edge((k-1)*d+i, n*d+j);
                }
            }
        }
    }

    if ( p == 0) {
        printf("0\n");
        return;
    }
    int num = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < n*d; ++v) {
        memset(used, false, sizeof(used));
        if (dfs(v)) {
            if (++num == p) {
                printf("%d\n",v/d + 1);
                return;
            }
        }
    }

    printf("impossible\n");
}

int
main()
{
    int num;
    scanf("%d",&num);
    for (int i=0; i<num; ++i) {
        scanf("%d %d",&Y,&X);
        for (int y=0; y<Y; ++y) {
            cin >> field[y];
        }
        solve();
    }
    return 0;
}