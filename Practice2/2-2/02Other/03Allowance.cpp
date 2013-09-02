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

#define INF (1<<26)

using namespace std;
typedef pair<int, int> P;

int N,C;
vector<P> coin;

bool
comp(const P &lhs,const P &rhs)
{
    return lhs.first > rhs.first;
}

bool
canFill(int i,long long res)
{
    long long crt = C-res;
    for (; i<N; ++i) {
        long long cnt = crt/coin[i].first + (crt%coin[i].first==0 ? 0 : 1);
        if (crt <= 0 || coin[i].second >= cnt) {
            return true;
        }
        crt -= coin[i].first*coin[i].second;
    }
    return false;
}

void
solve()
{
    sort(coin.begin(), coin.end(), comp);
    long long res = 0;
    //C以上のコインを使い切る
    for (int i=0; i<N; ++i) {
        if (coin[i].first >= C) {
            res += coin[i].second;
            coin[i].second = 0;
        }
    }

    long long crt = 0;
    while (canFill(0,0)) {
        crt = 0;
        bool isOver = false;
        vector<int> used(N,0);
        for (int i=0; i<N; ++i) {
            if (coin[i].second == 0)
                continue;

            long long diff = C - crt;
            int cnt = (int)diff/coin[i].first + isOver;
            if (cnt > coin[i].second) {
                cnt = coin[i].second;
            }
            used[i] = cnt + used[i];
            long long t = cnt * coin[i].first;
            crt += t;

            if (crt >= C) {
                break;
            }
            if (i==N-1 || !canFill(i+1,crt)) {
                --i;
                isOver = true;
            }
        }

        //usedの組み合わせで可能な限り消費する。
        int mn = INF;
        for (int i=0; i<N; ++i) {
            if (used[i] != 0) {
                mn = min(mn,coin[i].second/used[i]);
            }
        }
        for (int i=0; i<N; ++i) {
            coin[i].second -= mn*used[i];
        }
        res += mn;
    }

    printf("%lld\n",res);
}

int
main()
{
    scanf("%d %d",&N,&C);
    for (int i=0; i<N; ++i) {
        int v,b;
        scanf("%d %d",&v,&b);
        coin.push_back(P(v,b));
    }
    solve();
    return 0;
}
