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
#include <numeric>

#define INF (1<<30)

using namespace std;

#define MAX_C 2505

int C,L;
typedef pair<int, int> P;
priority_queue<P,vector<P>,greater<P> > lque;
vector<P> cvec;
bool used[MAX_C];

void
solve()
{
    int ans = 0;
    memset(used, false, sizeof(used));
    sort(cvec.begin(), cvec.end());
    while (!lque.empty()) {
        bool update = false;
        P l = lque.top();
        update = false;
        for (int i=0; i<C; ++i) {
            if (!used[i]) {
                used[i] = true;
                if (l.first < cvec[i].second) { // true:---|spf|--|mn|-> false:---|mn|-|spf|->
                    used[i] = false;
                }
                else if (l.first <= cvec[i].first) { // true:---|mn|--|spf|--|mx|--> false:---|mx|--|spf|->
                    update = true;
                    ++ans;
                    lque.pop();
                    if (l.second != 1) {
                        lque.push(P(l.first,--l.second));
                    }
                    break;
                }
            }
        }
        if (!update) {
            lque.pop();
        }
    }
    printf("%d\n",ans);
}

int
main()
{
    scanf("%d %d",&C,&L);
    for (int i=0; i<C; ++i) {
        int mn,mx;
        scanf("%d %d",&mn,&mx);
        cvec.push_back(P(mx,mn));
    }
    for (int i=0; i<L; ++i) {
        int spf,c;
        scanf("%d %d",&spf,&c);
        lque.push(P(spf,c));
    }
    solve();
}