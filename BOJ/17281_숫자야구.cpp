#include <iostream>
#include <vector>
using namespace std;
int ret = 0, n;
int arr[50][9], order[9] = { 0,0,0,1,0,0,0,0,0 };

void update() {
	int  yee = 0, cnt = 0, out = 0, score = 0;
	pair<int, int> runner[4];
	while (1) {
		if (out == 3) {
			if (yee == n - 1)break;
			for (int i = 0; i < 4; ++i) {
				runner[i].first = 0;
				runner[i].second = 0;
			}
			yee++;
			out = 0;
		}
		int state = arr[yee][order[cnt] - 1];
		if (state == 0) out++;
		else {
			for (int i = 0; i < 4; ++i) {
				if (runner[i].first == 0) {
					runner[i].first = 1; break;
				}
			}
			if (state == 1) {
				for (int i = 0; i < 4; ++i) {
					if(runner[i].first == 1) runner[i].second++;
				}
			}
			else if (state == 2) {
				for (int i = 0; i < 4; ++i) {
					if (runner[i].first == 1) runner[i].second += 2;
				}
			}
			else if (state == 3) {
				for (int i = 0; i < 4; ++i) {
					if (runner[i].first == 1) runner[i].second += 3;
				}
			}
			else if (state == 4) {
				for (int i = 0; i < 4; ++i) {
					if (runner[i].first == 1) runner[i].second += 4;
				}
			}
		}
		for (int i = 0; i < 4; ++i) {
			if (runner[i].second >= 4) {
				runner[i].first = 0;
				runner[i].second = 0;
				score++;
			}
		}
		cnt++;
		if (cnt == 9)cnt = 0;
	}
	if (ret < score)ret = score;
}

void dfs(int depth) {
	if (depth == 10) {
		update();
		return;
	}
	for (int i = 0; i < 9; ++i) {
		if (order[i] != 0)continue;
		order[i] = depth;
		dfs(depth + 1);
		order[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> arr[i][j];
	dfs(2);
	cout << ret;
	return 0;
}