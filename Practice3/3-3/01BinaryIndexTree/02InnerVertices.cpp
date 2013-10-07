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

#define INF (1<<30)
#define EPS 1e-6

using namespace std;

#define MAX_N 100050

long long bit0[MAX_N],bit1[MAX_N];
int _size;

int N;
int xs[MAX_N],ys[MAX_N];

int nums[MAX_N];

long long
sum(long long *b,int i)
{
    int s = 0;
    while (i > 0) {
        s += b[i];
        i -= (i & -i);
    }
    return s;
}

void
add(long long *b,int i,long long x)
{
    while (i <= MAX_N) {
        b[i] += x;
        i += (i & -i);
    }
}

//[0,n]
long long
sum(int i)
{
    return sum(bit1, i)*i + sum(bit0, i);
}

//(l,r]
long long
range_sum(int l,int r)
{
    return sum(r) - sum(l);
}

//[l,r]
void
range_add(int l,int r,long long x)
{
    add(bit0, l, -x*(l-1));
    add(bit1, l,  x);
    add(bit0, r,  x*r);
    add(bit1, r, -x);
}

int
compress(int p[])
{
    vector<int> ps;
    ps.resize(N);
    for (int i=0; i<N; ++i) {
        ps[i] = p[i];
    }
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    for (int i=0; i<N; ++i) {
        p[i] = 2 + (int)distance(ps.begin(), lower_bound(ps.begin(), ps.end(), p[i]));
    }
    return 2 + (int)ps.size();
}

bool
init()
{
    memset(bit0, 0, sizeof(bit0));
    memset(bit1, 0, sizeof(bit1));
    memset(xs, 0, sizeof(xs));
    memset(ys, 0, sizeof(ys));
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        scanf("%d %d",&xs[i],&ys[i]);
    }
    return true;
}

long long
solve()
{
    int X = compress(xs);
    int Y = compress(ys);
    vector<int> bs[MAX_N];
    for (int i=0; i<N; ++i) {
        bs[ys[i]].push_back(xs[i]);
    }

    bool covered[MAX_N];
    memset(covered, false, sizeof(covered));

    long long ans = N;
    for (int y=0; y<Y; ++y) {
        sort(bs[y].begin(), bs[y].end());
        int size = (int)bs[y].size();

        for (int i=0; i<size; ++i) {
            int x = bs[y][i];
            long long s = range_sum(x-1,x);

            if (covered[x]) {
                ans += s;
            }
            covered[x] = true;
            add(bit0, x, -s);
            if (i+1 < size) {
                if (x+1 < bs[y][i+1]-1) {
                    range_add(x+1, bs[y][i+1]-1, 1);
                }
                else if (x+1 == bs[y][i+1]-1) {
                    add(bit0, x+1, 1);
                }
            }
        }
    }

    return ans;
}

int
main()
{
    init();
    printf("%lld\n",solve());
    return 0;
}