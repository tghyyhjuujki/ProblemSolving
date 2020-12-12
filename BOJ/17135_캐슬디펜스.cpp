#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int ret = 0, n, m, d;
int arr[15][15];
vector<int> v;
vector<pair<int, int> > s;

struct SOL {int dist, r, c, index;};
priority_queue<SOL> pq;

bool operator<(SOL a, SOL b) {
	if (a.dist == b.dist)return a.c > b.c;
	return a.dist > b.dist;
}

void update() {
	int temp_ret = 0;
	vector<pair<int, int> > temp_s = s;
	for (int i =n; i > 0; --i) {
		vector<int> tt;
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < temp_s.size(); ++k) {
				int temp = abs(i - temp_s[k].first) + abs(v[j] - temp_s[k].second);
				if (temp_s[k].first >= i || temp_s[k].first == -1)continue;
				if (temp <= d)pq.push({ temp, temp_s[k].first, temp_s[k].second, k });
			}
			if (pq.size() > 0) {
				tt.push_back(pq.top().index);
				while (!pq.empty())pq.pop();
			}
		}
		for (int j = 0; j < tt.size(); ++j) {
			if (temp_s[tt[j]].first == -1)continue;
			temp_s[tt[j]].first = -1;
			temp_ret++;
		}
	}
	if (ret < temp_ret)ret = temp_ret;
}

void dfs(int depth, int x) {
	if (depth == 3) {
		update();
		return;
	}

	for (int i = x; i < m; ++i) {
		v.push_back(i);
		dfs(depth + 1, i + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)s.push_back({ i,j });
		}
	}

	dfs(0,0);
	cout << ret;
	return 0;
}