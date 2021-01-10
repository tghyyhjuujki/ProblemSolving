#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> stones, int k) {
	multimap<int, int, greater<int> > m;
	multimap<int, int>::iterator iter;
	int size = stones.size();

	// 길이가 k인 윈도 생성
	for (int i = 0; i < k; ++i)
		m.insert({ stones[i], i});

	//초항 처리
	iter = m.begin();
	int answer = iter->first;

	// 윈도 안에서 최대값 추출
	for (int i = 0; i < size - k; ++i) {

		//1씩 이동
		iter = m.find(stones[i]);
		m.erase(iter);
		m.insert({ stones[i + k], i + k});

		iter = m.begin();
		if (iter->first < answer)
			answer = iter->first;
	}
	return answer;
}