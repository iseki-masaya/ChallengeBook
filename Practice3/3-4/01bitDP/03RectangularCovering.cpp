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

#define INF (1<<28)
#define EPS 1e-8
#define MOD 100000000

using namespace std;

#define MAX_N 16

int N;
int x[MAX_N],y[MAX_N];

struct Rect {
  int cover,area;
    Rect(int c,int a) : cover(c) , area(a) {}
};

bool
init()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        scanf("%d%d",&x[i],&y[i]);
    }
    return N > 0;
}

bool
is_cover(int k,int i,int j)
{
    return
    (x[k] - x[i])*(x[k] - x[j]) <= 0 &&
    (y[k] - y[i])*(y[k] - y[j]) <= 0;
}

int
calc_area(int i,int j)
{
    int dx = max(abs(x[i] - x[j]),1);
    int dy = max(abs(y[i] - y[j]),1);
    return dx*dy;
}

int
solve()
{
    vector<Rect> rectangles;
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            Rect rect( (1<<i)|(1<<j) , calc_area(i,j));
            for (int k=0; k<N; ++k) {
                if (k != i && k != j && is_cover(k, i, j)) {
                    rect.cover |= (1<<k);
                }
            }
            rectangles.push_back(rect);
        }
    }

    vector<int> dp(1<<N,INF);
    dp[0] = 0;
    for (int i=0; i<rectangles.size(); ++i) {
        int cover = rectangles[i].cover;
        for (int s=0; s<(1<<N); ++s) {
            if (dp[s] != INF && (s | cover) != s ) {
                dp[s|cover] = min(dp[s|cover],dp[s] + rectangles[i].area);
            }
        }
    }
    return dp[(1<<N)-1];
}

int
main()
{
    while (init()) {
        printf("%d\n",solve());
    }
    return 0;
}