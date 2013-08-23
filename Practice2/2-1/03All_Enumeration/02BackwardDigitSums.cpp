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

int N,S;

int
calc(vector<int> v)
{
    for (int i=(int)v.size()-1; i>0; --i) {
        for (int j=0; j<i; ++j) {
            v[j] = v[j]+v[j+1];
        }
    }
    return v[0];
}

int
main()
{
    scanf("%d %d",&N,&S);
    vector<int> v(N);
    for (int i=1; i<=N; ++i) {
        v[i-1] = i;
    }
    do {
        if (calc(v)==S) {
            for (int i=0; i<v.size(); ++i) {
                printf("%d%c",v[i],v.size()==i+1?'\n':' ');
            }
            break;
        }
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}