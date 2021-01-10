#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int& mid, int& k, vector<int>& stones) {
	int cnt = 0;
	int size = stones.size();
	for (int i = 0; i < size; ++i) {
	
		// 연속가능한 돌이면 +1
		if (stones[i] <= mid)
			cnt++;
		// 연속 불가능하면 초기화
		else 
			cnt = 0;
		// 연속 가능한 돌이 k 이상이면 true
		if (cnt >= k)return true;
	}
	return false;
}

int solution(vector<int> stones, int k) {
	//start, mid, end 포인트 설정
	int s = 1, mid, e = *max_element(stones.begin(), stones.end());

	//이분탐색
	while (s <= e) {
		mid = (s + e) / 2;
		// 중간으로 자른 범위에서 연속하는 구간이 나오면
		if (check(mid, k, stones))
			e = mid - 1;
        // 나오지 않으면
		else
			s = mid + 1;
	}
	return s;
}