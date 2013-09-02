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

#define SIZE_N 6
#define INF (1<<26)

using namespace std;

int cnt[SIZE_N];

void
solve()
{
    //
    int res = 0;

    for (int i=5; i >= 0; --i) {
        res += cnt[i];

    }

    res += cnt[5];

    res += cnt[4];
    cnt[0] -= min(11*cnt[4],cnt[0]);

    res += cnt[3];
    int num_two = min(cnt[1],5*cnt[3]);
    cnt[1] -= num_two;
    int emp_two = 5*cnt[3]-num_two;
    cnt[0] -= min(cnt[0],4*emp_two);

    int num_thr = (cnt[2]%4==0 ? 0 : 1) + cnt[2]/4;
    res += num_thr;
    int emp_thr = 0;
    int emp_one = 0;
    switch (cnt[2]%4) {
        case 0:
            emp_thr = 0;
            emp_one = 0;
            break;
        case 1:
            emp_thr = 5;
            emp_one = 7;
            break;
        case 2:
            emp_thr = 3;
            emp_one = 6;
            break;
        case 3:
            emp_thr = 1;
            emp_one = 5;
            break;
    }
    num_two = min(cnt[1],emp_thr);
    emp_two = emp_thr - num_two;
    cnt[1] -= num_two;
    cnt[0] -= min(cnt[0],4*emp_two+emp_one);

    num_two = (cnt[1]%9==0 ? 0 : 1) + cnt[1]/9;
    res += num_two;
    emp_two = 9-cnt[1]%9;
    if (emp_two == 9)
        emp_two = 0;
    cnt[0] -= min(cnt[0],4*emp_two);

    res += (cnt[0]%36==0 ? 0 : 1) + cnt[0]/36;

    printf("%d\n",res);
}

int
main()
{
    while (true) {
        bool is_all_zero = true;
        for (int i=0; i<SIZE_N; ++i) {
            scanf("%d",&cnt[i]);
            if (cnt[i] != 0)
                is_all_zero = false;
        }
        if (is_all_zero)
            break;

        solve();
    }
    return 0;
}

