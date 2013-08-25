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

#define MAX_V 500
#define INF (1<<26)
#define MAX_N 100
#define MAX_M 100

int N,M;
int X[MAX_N],Y[MAX_N],B[MAX_N];
int P[MAX_M],Q[MAX_M],C[MAX_M];
int E[MAX_N][MAX_M];

int g[MAX_V][MAX_V];
int prevs[MAX_V][MAX_V];
bool used[MAX_V];

void
solve()
{
    int V = N+M+1;
    for (int i=0; i<V; ++i) {
        fill(g[i], g[i]+V, INF);
    }
    for (int j=0; j<M; ++j) {
        int sum = 0;
        for (int i=0; i<N; ++i) {
            int c = abs(X[i]-P[j]) + abs(Y[i]-Q[j]) + 1;
            g[i][N+j] = c;
            if (E[i][j] > 0) {
                g[N+j][i] = -c;
            }
            sum += E[i][j];
        }
        if (sum > 0) {
            g[N+M][N+j] = 0;
        }
        if (sum < C[j]) {
            g[N+j][N+M] = 0;
        }
    }

    for (int i=0; i<V; ++i) {
        for (int j=0; j<V; ++j) {
            prevs[i][j] = i;
        }
    }

    for (int k=0; k<V; ++k) {
        for (int i=0; i<V; ++i) {
            for (int j=0; j<V; ++j) {
                if (g[i][j] > g[i][k]+g[k][j]) {
                    g[i][j] = g[i][k]+g[k][j];
                    prevs[i][j] = prevs[k][j];
                    if (i==j && g[i][i] < 0) {
                        fill(used, used+V, false);
                        for (int v=i; !used[v]; v = prevs[i][v]) {
                            used[v] = true;
                            if (v!=N+M && prevs[i][v] != N+M) {
                                if (v >= N) {
                                    E[prevs[i][v]][v-N]++;
                                }
                                else {
                                    E[v][prevs[i][v]-N]--;
                                }
                            }
                        }
                        printf("SUBOPTIMAL\n");
                        for (int x=0; x<N; ++x) {
                            for (int y=0; y<M; ++y) {
                                printf("%d%c",E[x][y],y+1==M?'\n':' ');
                            }
                        }
                        return;
                    }
                }
            }
        }
    }

    printf("OPTIMAL\n");
}

int
main()
{
    scanf("%d %d",&N,&M);
    for (int i=0; i<N; ++i) {
        scanf("%d %d %d",&X[i],&Y[i],&B[i]);
    }
    for (int i=0; i<M; ++i) {
        scanf("%d %d %d",&P[i],&Q[i],&C[i]);
    }
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            scanf("%d",&E[i][j]);
        }
    }
    solve();
}