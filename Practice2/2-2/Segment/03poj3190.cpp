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

struct P {
  int s,t,n;
};
typedef pair<int, int> C;
vector<P> p;
int N;

bool
comp(const P &lhs,const P &rhs)
{
    return lhs.s < rhs.s;
}

void
solve()
{
    sort(p.begin(), p.end(), comp);
    priority_queue<C,vector<C>,greater<C>   > que;
    vector<int> alloc(N);
    int res = 0;
    que.push(C(p[0].t,++res));
    alloc[0] = res;
    for (int i=1; i<p.size(); ++i) {
        C c = que.top();
        int num;
        if (p[i].s > c.first) {
            que.pop();
            que.push(C(p[i].t,c.second));
            num = c.second;
        }
        else {
            que.push(C(p[i].t,++res));
            num = res;
        }
        alloc[p[i].n] = num;
    }
    printf("%d\n",res);
    for (int i=0; i<N; ++i) {
        printf("%d\n",alloc[i]);
    }
}

int
main()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        P tp;
        tp.n = i;
        scanf("%d %d",&tp.s,&tp.t);
        p.push_back(tp);
    }
    solve();
}