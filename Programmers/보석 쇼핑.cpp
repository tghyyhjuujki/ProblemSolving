#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	map<string, int> gem_list;
	priority_queue<pair<int, string> > temp_gem;
	int size = gems.size();
	int start_idx = 0, end_idx = 0, distance = 100001;
	answer.push_back(0);
	answer.push_back(0);

	//일단 맵에 다 저장
	for (int i = 0; i < size; ++i)
		gem_list[gems[i]]++;

	int gem_cnt = gem_list.size();
	gem_list.clear();
	gem_list[gems[0]]++;

	while (true) {
		// 모든 종류의 보석이 있으면
		
		if (gem_cnt == gem_list.size()) {
			// 기존 길이보다 짧으면
			if (end_idx - start_idx < distance) {
				distance = end_idx - start_idx;
				answer[0] = start_idx;
				answer[1] = end_idx;
			}
			//기존 길이와 같거나 크면
			else {
				//gem_list.erase(gems[start_idx]);
				gem_list[gems[start_idx]]--;
				if (gem_list[gems[start_idx]] == 0)
					gem_list.erase(gems[start_idx]);
				start_idx++;
			}
		}
		// 모든 보석 없으면
		else {
			end_idx++;
			if (end_idx == size)break;
			gem_list[gems[end_idx]]++;
		}
	}
	answer[0]++;
	answer[1]++;
	return answer;
}