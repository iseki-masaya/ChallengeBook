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

using namespace std;

#define MAX_N 1005
#define MAX_K 105

#define DEC_SIZE 40

int N,K;
int dp[MAX_N][DEC_SIZE];

void
add(int n,int m)
{
    for (int i=0; i<DEC_SIZE; ++i) {
        dp[n][i] += dp[m][i];
        if (dp[n][i] >= 10) {
            dp[n][i] -= 10;
            dp[n][i+1]++;
        }
    }
}

void
solve()
{
    dp[0][0] = 1;
    for (int i=1; i<=K; ++i) {
        for (int j=i; j<=N; ++j) {
            add(j, j-i);
        }
    }
    int lv=40;
    while (dp[N][--lv] == 0);
    for (int i=lv; i>=0; --i) {
        printf("%d",dp[N][i]);
    }
    printf("\n");
}

int
main()
{
    scanf("%d %d",&N,&K);
    solve();
}