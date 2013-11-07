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
#include <bitset>

const int INF = (1<<30);
#define EPS 1e-8
const int MOD = 10007;

using namespace std;

typedef vector<long long> vec;
typedef vector<vec> mat;

long long M;
mat T;

mat
mult(mat &A,mat &B)
{
    int N = (int)A.size();
    mat C(N,vec(N,0));
    for (int i=0; i<N; ++i) {
        for (int k=0; k<N-1; ++k) if (A[i][k]) {
            for (int j=0; j<N-1; ++j) if (B[k][j]) {
                C[i][j] = 1;
                break;
            }
            C[i][N-1] += A[i][N-1] + B[k][N-1];
            break;
        }
        if (!C[i][N-1]) {
            C[i][N-1] = A[i][N-1];
        }
    }
//  for (int i=0; i<N; ++i) {
//      for (int k=0; k<N; ++k) if (A[i][k]) {
//          for (int j=0; j<N; ++j) {
//              C[i][j] += A[i][k]*B[k][j];
//          }
//      }
//  }
    return C;
}

mat
exp(mat A,long long n)
{
    int N = (int)A.size();
    mat C(N,vec(N,0));
    for (int i=0;i<N;++i) C[i][i] = 1;
    while (n) {
        if (n&1) {
            C = mult(C, A);
        }
        A = mult(A, A);
        n >>= 1;
    }
    return C;
}

bool
init()
{
    long long n,k;
    scanf("%lld%lld%lld",&n,&M,&k);
    if (n==0 && M==0 && k==0) {
        return false;
    }
    T.clear();
    T.resize(n+1,vec(n+1,0));
    for (int i=0; i<=n; ++i) T[i][i] = 1;
    for (int i=0; i<k; ++i) {
        char s[5];
        scanf("%s",s);
        if (s[0] == 'g') {
            int a;
            scanf("%d",&a);
            --a;
            T[a][n]++;
        }
        else if (s[0] == 'e') {
            int a;
            scanf("%d",&a);
            --a;
            for (int j=0; j<=n; ++j) {
                T[a][j] = 0;
            }
        }
        else {
            int a,b;
            scanf("%d%d",&a,&b);
            --a , --b;
            swap(T[a], T[b]);
        }
    }
    return true;
}

void
solve()
{
    T = exp(T,M);
    int N = (int)T.size()-1;
    for (int i=0; i<N; ++i) {
        printf("%lld%c",T[i][N],i+1==N ? '\n' :' ');
    }
}

int
main()
{
    while (init()) {
        solve();
    }
    return 0;
}