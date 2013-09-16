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

int size,val;

long long
gcd(long long a,long long b)
{
    long long c = a%b;
    if (c == 0) {
        return b;
    }
    return gcd(b, c);
}

void
solve()
{
    int n=val;
    long long mna=0,mnb=1e18;
    for (int i=1,j=1; i<=size; ++i) {
        long long a,b;
        n /= 10;
        j *= 10;
        a = val - n;
        b = (long long)pow(10.0, size-i)*(j-1);
        long long g = gcd(a, b);
        a /= g , b/= g;
        if (b < mnb) {
            mna = a;
            mnb = b;
        }
    }
    printf("%lld/%lld\n",mna,mnb);
}

int
main()
{
    string str;
    while (cin) {
        cin >> str;
        if(str.size() == 1) {
            break;
        }
        val = 0;
        size = 0;
        for (int i=2; str[i] != '.'; ++i) {
            val = val*10 + str[i] - '0';
            ++size;
        }
        solve();
    }
    return 0;
}
