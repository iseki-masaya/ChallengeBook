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

using namespace std;

#define INF (1<<20)
#define PI 3.14159265

struct point {
  double x,y;
};

double
calc_dist(double bx,double by,double cx,double cy)
{
	return sqrt((bx-cx)*(bx-cx)+(by-cy)*(by-cy));
}

double
get_angle(point base,point target,double angle)
{
	double ans;
	if (target.x > base.x) {
		ans = atan(((double)target.y-base.y)/(target.x-target.y));
	}
	else if (target.x < base.x) {
		ans = PI + atan(((double)target.y-base.y)/(target.x-target.y));
	}
	else if (target.x == base.x && target.y > base.y) {
		ans = PI/2.0;
	}
	else if (target.x == base.x && target.y < base.y) {
		ans = -PI*3.0/2.0;
	}
	else {
		ans = 0;
		cout << " error";
	}
	ans -= PI*(angle/180.0);
	return ans;
}

point
calc_point(point base,point target,double angle)
{
	point res;
	double r = calc_dist(base.x,base.y,target.x,target.y);
	double theta = get_angle(base,target,angle);
	res.x = base.x + r*cos(theta);
	res.y = base.y + r*sin(theta);
	return res;
}

void
solve(int N,int C,vector<int> &L,vector<int> &S,vector<int> &A)
{
	vector<point> ps(N+1); // N is answer.
	point p;
	p.x = 0; p.y = 0;
	ps[0] = p;
	for (int i=1; i<=N; ++i) {
		p.y += L[i-1];
		ps[i] = p;
	}
	for (int op_num=0; op_num<C; ++op_num) {
		int base_point = S[op_num];
		for (int pos = base_point+1; pos<=N; ++pos) {
			ps[pos] = calc_point(ps[base_point],ps[pos],(double)A[op_num]);
		}
		printf("%.2f %.2f\n",ps[N].x,ps[N].y);
	}
}

int
main()
{
	int N,C;
	while (scanf("%d %d",&N,&C) != EOF) {
		vector<int> L(N);
		for (int i=0; i<N; ++i) {
			scanf("%d",&L[i]);
		}
		vector<int> S(C),A(C);
		for (int i=0; i<C; ++i) {
			scanf("%d %d",&S[i],&A[i]);
		}
		solve(N,C,L,S,A);
		printf("\n");
	}
}
