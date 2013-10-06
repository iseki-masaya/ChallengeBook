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

#define INF (1<<30)
#define EPS 1e-6

using namespace std;

#define MAX_N 1005

int X1[MAX_N],X2[MAX_N],Y1[MAX_N],Y2[MAX_N];
int W,H;
int N;
typedef pair<int, int> P;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
bool fld[6*MAX_N][6*MAX_N];

bool
init()
{
    scanf("%d %d",&W,&H);
    W *= 2 , H *= 2;
    if (H == 0 && W == 0) {
        return false;
    }
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        scanf("%d %d %d %d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
        X1[i] *= 2 , Y1[i] *= 2 , X2[i] *= 2 , Y2[i] *= 2;
    }
    return true;
}

int
compress(int *x1,int *x2,int w)
{
    vector<int> xs;
    for (int i=0; i<N; ++i) {
        for (int d=-1; d<=1; ++d) {
            int tx1 = x1[i] + d , tx2 = x2[i] + d;
            if (0 <= tx1 && tx1 <= w) xs.push_back(tx1);
            if (0 <= tx2 && tx2 <= w) xs.push_back(tx2);
        }
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    for (int i=0; i<N; ++i) {
        x1[i] = (int)distance(xs.begin(), find(xs.begin(), xs.end(), x1[i]));
        x2[i] = (int)distance(xs.begin(), find(xs.begin(), xs.end(), x2[i]));
    }

    return (int)xs.size()-1;
}

void
solve()
{
    memset(fld, false, sizeof(fld));
    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);

    for (int i=0; i<N; ++i) {
        for (int x = X1[i]; x <= X2[i]; ++x) {
            for (int y = Y1[i]; y <= Y2[i]; ++y) {
                fld[y][x] = true;
            }
        }
    }

    int ans = 0;
    for (int x = 0; x <= W; ++x) {
        for (int y = 0; y <= H; ++y) {
            if (fld[y][x]) {
                continue;
            }
            ++ans;

            queue<P> que;
            que.push(P(x,y));
            fld[y][x] = true;
            while (!que.empty()) {
                int sx = que.front().first , sy = que.front().second;
                que.pop();

                for (int i=0; i<4; ++i) {
                    int cx = sx + dx[i] , cy = sy + dy[i];
                    if (0 <= cx && cx <= W && 0 <= cy && cy <= H && !fld[cy][cx]) {
                        fld[cy][cx] = true;
                        que.push(P(cx,cy));
                    }
                }
            }
        }
    }

    printf("%d\n",ans);
}

int
main()
{
    while (init()) {
        solve();
    }
    return 0;
}