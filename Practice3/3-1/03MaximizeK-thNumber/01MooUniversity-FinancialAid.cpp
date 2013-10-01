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

typedef pair<int, int> P;
vector<P> svec,fvec;
int N,C,F;

bool
isOk(int m)
{
    int mid_score = svec[m].first;
		int f         =	svec[m].second;
    int mid_pos = (N-1)/2;
    int lnum=0,unum=0,mnum=0;

    bool isSame = false;
    for (int i=0; i<C; ++i) {
        if (!isSame && svec[m].first==fvec[i].second && svec[m].second==fvec[i].first) {
            isSame = true;
            continue;
        }
        if (f+fvec[i].first > F) {
            break;
        }
			
        if (fvec[i].second < mid_score && lnum < mid_pos) {
            f += fvec[i].first;
            ++lnum;
        }
        else if (fvec[i].second > mid_score && unum < mid_pos) {
            f += fvec[i].first;
            ++unum;
        }
        else if (fvec[i].second == mid_score){
            f += fvec[i].first;
            ++mnum;
        }
    }

    int s = (lnum-mid_pos) + (unum-mid_pos) + mnum;
    if (s < 0) {
        return false;
    }
    return true;
}

void
solve()
{
    int lb=-1,ub=C;
    sort(fvec.begin(), fvec.end());
    sort(svec.begin(), svec.end());
    while (ub-lb > 1) {
        int mid = (ub+lb)/2;
        if (isOk(mid)) {
            lb = mid;
        }
        else {
            ub = mid;
        }
    }
    if (lb == -1) {
        printf("-1\n");
    }
    else {
        printf("%d\n",svec[lb].first);
    }
}

int
main()
{
    scanf("%d %d %d",&N,&C,&F);
    for (int i=0; i<C; ++i) {
        int s,f;
        scanf("%d %d",&s,&f);
        fvec.push_back(P(f,s));
        svec.push_back(P(s,f));
    }
    solve();
}
