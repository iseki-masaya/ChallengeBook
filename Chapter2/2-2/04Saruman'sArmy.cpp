#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	while (true) {
		int N,R;
		cin >> R >> N;
		if(R == -1 && N == -1) break;

		vector<int> pos;
		int tmp;
		for (int i=0; i<N; ++i) {
			cin >> tmp;
			pos.push_back(tmp);
		}
		sort(pos.begin(), pos.end());

		int cnt = 1;
		bool isPointed = false;
		int val = pos.at(0)+R;
		for (int i=1; i<pos.size(); ++i) {
			if (val < pos.at(i)) {
				if (isPointed) {
					++cnt;
					isPointed = false;
				}
				else {
					--i;
					isPointed = true;
				}
				val = pos.at(i)+R;
			}
		}

		cout << cnt << endl;

		pos.clear();
	}

	return 0;
}