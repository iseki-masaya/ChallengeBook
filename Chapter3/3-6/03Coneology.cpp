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

#define MAX_N 40005

int N;
double x[MAX_N],y[MAX_N],r[MAX_N];

bool
inside(int i,int j)
{
    double dx = x[i] - x[j] , dy = y[i] - y[j];
    return dx*dx + dy*dy <= r[j]*r[j];
}

void
solve()
{
    vector<pair<double, int> > events;
    for (int i=0; i<N; ++i) {
        events.push_back(make_pair(x[i]-r[i], i));
        events.push_back(make_pair(x[i]+r[i], i+N));
    }
    sort(events.begin(), events.end());

    set<pair<double, int> > outers;
    vector<int> res;
    for (int i=0; i<events.size(); ++i) {
        int id = events[i].second % N;
        if (events[i].second < N) {
            set<pair<double, int> >::iterator it = outers.lower_bound(make_pair(y[id], id));
            if (it != outers.end() && inside(id, it->second)) continue;
            if (it != outers.begin() && inside(id, (--it)->second)) continue;
            res.push_back(id);
            outers.insert(make_pair(y[id], id));
        }
        else {
            outers.erase(make_pair(y[id], id));
        }
    }

    sort(res.begin(), res.end());
    printf("%d\n",(int)res.size());
    for (int i=0; i<res.size(); ++i) {
        printf("%d%c",res[i]+1,i+1==res.size()?'\n':' ');
    }
}

int
main()
{
    scanf("%d",&N);
    for (int i=0; i<N; ++i) {
        scanf("%lf %lf %lf",&r[i],&x[i],&y[i]);
    }
    solve();
}