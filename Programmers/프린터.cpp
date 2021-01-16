#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct WAITING {
	int idx, val;
};

int solution(vector<int> priorities, int location) {
	int answer = 0, _size = priorities.size();
	queue<WAITING> q;
	for (int i = 0; i < _size; ++i)
		q.push({ i, priorities[i] });

	sort(priorities.begin(), priorities.end());

	while (true) {
		int idx = q.front().idx;
		int val = q.front().val;
		q.pop();
		if (priorities[priorities.size() - 1] == val) {
            answer++;
			if (idx == location)
				break;
			
			priorities.pop_back();
			continue;
		}
		q.push({ idx, val });	
	}
	return answer;
}