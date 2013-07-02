#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>

#define FILE

using namespace std;

ofstream ofs("/Users/iseki/Downloads/ans.dat");
#ifdef FILE
ifstream ifs( "/Users/iseki/Downloads/A-large-practice (2).in" );
#endif

template <typename T>
void
in(T &arg) {
#ifdef FILE
	ifs >> arg;
#endif
#ifndef FILE
	cin >> arg;
#endif
}

template <typename T>
void
out(T &arg,int i) {
	string str = "Case #";
	ofs << str << i << ": " << arg << endl;
	cout << str << i << ": " << arg << endl;
}

bool
isSat(vector<string> &mat,int pos,int cdt)
{
	for (int i=cdt+1; i<mat.size(); ++i) {
		if (mat[pos][i] == '1') {
			return false;
		}
	}
	return true;
}

int bubble(vector<string> &mat,int to,int from)
{
	int ret = 0;
	while (from != to) {
		swap(mat[from],mat[from-1]);
		++ret;
		--from;
	}
	return ret;
}

int
solve(vector<string> &mat)
{
	int ans = 0;
	for (int i=0; i<mat.size(); ++i) {
		if (!isSat(mat,i,i)) {
			for (int j=i+1; j<mat.size(); ++j) {
				if (isSat(mat,j,i)) {
					ans += bubble(mat,i,j);
					break;
				}
			}
		}
	}
	return ans;
}

int
main()
{
	int num;
	in(num);

	for (int i=1; i<=num; ++i) {
		int size;
		in(size);
		vector<string> mat;
		for (int j=0; j<size; ++j) {
			string str;
			in(str);
			mat.push_back(str);
		}
		int ans = solve(mat);
		out(ans, i);
	}

	return 0;
}