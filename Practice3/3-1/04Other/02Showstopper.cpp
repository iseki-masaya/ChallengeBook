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
#include <numeric>

#define L_INF (1)
#define INF (1<<29)
#define EPS 1e-6

using namespace std;

#define MAX 5000000

int N;
unsigned int X[MAX],Y[MAX],Z[MAX];
int mx_cnt[MAX];
char buff[1024];

bool
init(){
    int f = 0;
    N = 0;
    while((f = ((gets(buff)!=NULL))) && strlen(buff) > 2){
        sscanf(buff, "%u%u%u", &X[N], &Y[N], &Z[N]);
        N++;
    }

    return f || N > 0;
}

bool
check(unsigned int m)
{
    unsigned int cnt = 0;
    for (int i=0; i<N; ++i) {
        if (Y[i] <= m) {
            cnt ^= mx_cnt[i];
        }
        else if (X[i] <= m) {
            cnt ^= (m - X[i])/Z[i] + 1;
        }
    }

    return cnt&1;
}

void
solve()
{
    if (!N) {
        return;
    }
    unsigned int cnt = 0;
    for (int i=0; i<N; ++i) {
        mx_cnt[i] = (Y[i] - X[i])/Z[i] + 1;
        cnt ^= mx_cnt[i];
    }
    if (!(cnt&1)) {
        puts("no corruption");
        return;
    }

    unsigned int lb = 0 , ub = 0xffffffff ,md;
    while (ub - lb > 1) {
        md = (unsigned int)(((long long)ub+lb)/2LL);
        if (check(md)) {
            ub = md;
        }
        else {
            lb = md;
        }
    }

    cnt = 0;
    for (int i=0; i<N; ++i) {
        if (X[i] <= ub && ub <= Y[i] && (ub-X[i])%Z[i] == 0 ) {
            ++cnt;
        }
    }
    printf("%u %u\n",ub,cnt);
}

int
main()
{
    while (init()) {
        solve();
    }
    return 0;
}