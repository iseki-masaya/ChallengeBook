/*
          mem   time
 bfs      464k  157ms
 dijkstra 384k  94ms
 */

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

//#define DEB

using namespace std;

#define MAX_PRIME 10001
#define PRIME_SIZE 1500 //
#define LB_PRIME 1000

struct edge {
  int from,to,cost;
    edge() {}
    edge(int f,int t,int c) : from(f),to(t),cost(c) {}
};
typedef pair<int, int> P;
vector<edge> G[PRIME_SIZE];
vector<int> primes;
bool is_prime[MAX_PRIME];
int d[PRIME_SIZE];

int src,dst;

bool
can_reach(int a,int b)
{
    int diff = 0;
    for (int i=0; i<4; ++i) {
        int va = a%10;
        int vb = b%10;
        a /= 10 , b/= 10;
        if (va != vb) {
            ++diff;
        }
    }
    return diff <= 1 ? true : false;
}

void
sieve()
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i<MAX_PRIME; ++i) {
        if (is_prime[i]) {
            if (i >= LB_PRIME) {
                primes.push_back(i);
            }
            for (int j=2*i; j<MAX_PRIME; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}

void
dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d, d+PRIME_SIZE, INF);
    que.push(P(0,s));
    d[s] = 0;
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) {
            continue;
        }
        for (int u=0; u<G[v].size(); ++u) {
            edge e = G[v][u];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

void
trace_dijkstra(int s,int didx)
{
    bool used[PRIME_SIZE];
    int prv[PRIME_SIZE];
    int V = (int)primes.size();

    fill(d, d+PRIME_SIZE, INF);
    memset(used, false, sizeof(used));
    memset(prv, -1, sizeof(prv));
    d[s] = 0;

    while (true) {
        int v = -1;
        for (int u=0; u<V; ++u) {
            if (!used[u] && (v==-1 || d[u] < d[v])) {
                v = u;
            }
        }
        if (v == -1) {
            break;
        }

        used[v] = true;
        for (int u=0; u<G[v].size(); ++u) {
            edge e = G[v][u];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                prv[e.to] = v;
            }
        }
    }

    vector<int> path;
    for (; didx != -1; didx = prv[didx]) {
        path.push_back(didx);
    }
    reverse(path.begin(), path.end());
//  for (int t : path)
//      cout << primes[t] << endl;
}

void
solve()
{
    int sidx = (int)distance(primes.begin(),lower_bound(primes.begin(), primes.end(), src));
    int didx = (int)distance(primes.begin(),lower_bound(primes.begin(), primes.end(), dst));
#ifdef DEB
    trace_dijkstra(sidx, didx);
#else
    dijkstra(sidx);
#endif
    printf("%d\n",d[didx]);
}

void
solve_bfs()
{
    int sidx = (int)distance(primes.begin(),lower_bound(primes.begin(), primes.end(), src));
    int didx = (int)distance(primes.begin(),lower_bound(primes.begin(), primes.end(), dst));
    queue<P> que;
    bool used[PRIME_SIZE];
    memset(used, false, sizeof(used));

    que.push(P(0,sidx)); //first:depth second:vertex
    while (!que.empty()) {
        P p = que.front();
        que.pop();
        int v = p.second;
        if (used[v]) {
            continue;
        }
        used[v] = true;
        if (v == didx) {
            printf("%d\n",p.first);
            return;
        }

        for (int u=0; u<G[v].size(); ++u) {
            edge e = G[v][u];
            que.push(P(p.first+1,e.to));
        }
    }
}

int
main()
{
    sieve();
    for (int i=0; i<primes.size(); ++i) {
        for (int j=i+1; j<primes.size(); ++j) {
            if (i != j && can_reach(primes[i], primes[j])) {
                G[i].push_back(edge(i,j,1));
                G[j].push_back(edge(j,i,1));
            }
        }
    }

    int T;
    scanf("%d",&T);
    for (int i=0; i<T; ++i) {
        scanf("%d %d",&src,&dst);
        solve();
//      solve_bfs();
    }
    return 0;
}