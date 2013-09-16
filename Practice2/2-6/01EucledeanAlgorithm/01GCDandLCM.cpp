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

#define INF 10000000000
#define EPS 1e-6

using namespace std;

long long
gcd(long long a,long long b)
{
    long long c = a%b;
    if (c == 0) {
        return b;
    }
    return gcd(b, c);
}

int
main()
{
    long long a,b;
    while (scanf("%lld %lld",&a,&b) != EOF) {
        long long g = gcd(a, b);
        long long l = (a/g)*b;
        printf("%lld %lld\n",g,l);
    }
    return 0;
}