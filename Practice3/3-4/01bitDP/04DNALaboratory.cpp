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

#define INF (1<<28)
#define EPS 1e-8
#define MOD 100000000

using namespace std;

#define MAX_N 16

int N;
vector<string> dena;
int common[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];
bool ok[1 << MAX_N][MAX_N];

bool
init()
{
    scanf("%d",&N);
    dena.resize(N);
    for (int i=0; i<N; ++i) {
        cin >> dena[i];
    }
    return true;
}

vector<string>
remove_ignorable_string(vector<string> &S)
{
    bitset<MAX_N> can_remove;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (i != j ) {
                if (!can_remove[i] && S[i].find(S[j]) != string::npos) {
                    can_remove[j] = true;
                }
            }
        }
    }
    vector<string> res;
    for (int i=0; i<N; ++i) {
        if (!can_remove[i]) {
            res.push_back(S[i]);
        }
    }
    return res;
}

int
common_part(string &head,string &tail)
{
    int H = (int)head.size();
    for (int i=0; i<H; ++i) {
        if (head[i] == tail[0]) {
            string s = head.substr(i);
            if (tail.find(s) == 0) {
                return (int)s.size();
            }
        }
    }
    return 0;
}

void
calc_common_part(vector<string> &S)
{
    memset(common, 0, sizeof(common));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (i != j) {
                common[i][j] = common_part(S[i], S[j]);
            }
        }
    }
}

void
dfs(int state,int last,string cur,string &best,vector<string> &S)
{
    if (state == (1<<N)-1) {
        if (cur < best) {
            best = cur;
        }
        return;
    }

    for (int i=0; i<N; ++i) {
        if ( !(state & (1<<i)) && ok[state|(1<<i)][i]) {
            if (dp[state][last] + S[i].size() - common[last][i] == dp[state|(1<<i)][i]) {
                string s = cur + S[i].substr(common[last][i]);
                if (s < best) {
                    dfs(state|(1<<i), i, s, best, S);
                }
            }
        }
    }
}

string
solve()
{
    vector<string> S = remove_ignorable_string(dena);
    sort(S.begin(), S.end());
    N = (int)S.size();

    calc_common_part(S);

    for (int i=0; i<(1<<N); ++i) {
        fill(dp[i], dp[i]+N, INF);
    }
    for (int i=0; i<N; ++i) {
        dp[1 << i][i] = (int)S[i].size();
    }

    for (int s=0; s < (1<<N); ++s) {
        for (int i=0; i<N; ++i) if (dp[s][i] != INF) {
            for (int j=0; j<N; ++j) if ( !(s&(1<<j)) ) {
                int next_s = ( s | (1<<j) );
                dp[next_s][j] = min(dp[next_s][j],dp[s][i] + (int)S[j].size() - common[i][j]);
            }
        }
    }

    int mn = INF;
    for (int i=0; i<N; ++i) {
        mn = min(mn,dp[(1<<N)-1][i]);
    }

    memset(ok, false, sizeof(ok));
    for (int i=0; i<N; ++i) {
        if (dp[(1<<N)-1][i] == mn) {
            ok[(1<<N)-1][i] = true;
        }
    }
    for (int s = (1<<N)-1; s >= 0; --s) {
        for (int i=0; i<N; ++i) if(ok[s][i]) {
            for (int j=0; j<N; ++j) if(i != j && (s & (1<<i))) {
                if (dp[s & ~(1<<i)][j] == dp[s][i] - S[i].size() + common[j][i]) {
                    ok[s & ~(1<<i)][j] = true;
                }
            }
        }
    }

    string best = "Z";
    for (int i=0; i<N; ++i) {
        if (ok[1<<i][i]) {
            dfs(1<<i, i, S[i], best, S);
        }
    }
    return best;
}

int
main()
{
    int num;
    scanf("%d",&num);
    for (int i=1; i<=num; ++i) {
        init();
        printf("Scenario #%d:\n",i);
        printf("%s\n\n",solve().c_str());
    }
    return 0;
}