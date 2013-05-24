#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Schedule
{
private:
	struct Task {
		int start;
		int end;
	};
	struct comp {
		bool operator()(const Task &lhs,const Task &rhs)
		{
			return lhs.end < rhs.end;
		}
	};
public:
	int getMax(int n,vector<int> s,vector<int> t)
	{
		vector<Task> task;
		for (int i=0; i<n; ++i) {
			Task tmp;
			tmp.start = s.at(i);
			tmp.end = t.at(i);
			task.push_back(tmp);
		}
		comp cmp;
		sort(task.begin(), task.end(), cmp);

		int now = 0,cnt = 0;
		for (int i=0; i<task.size(); ++i) {
			if (now <= task.at(i).start) {
				now = task.at(i).end;
				++cnt;
			}
		}
		return cnt;
	}
};