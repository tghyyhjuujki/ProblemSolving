#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int n, ret = 0, m, t, x, d, k;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
deque<int> dq[51];
queue<pair<int, int> > q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> t;
	int temp;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {

			cin >> temp;
			dq[i].push_back(temp);
		}
	}

	for (int i = 0; i < t; ++i) {
		cin >> x >> d >> k;
		for (int j = x; j <= n; j += x) {
			if (d == 0) {
				for (int l = 0; l < k; ++l) {
					temp = dq[j].back();
					dq[j].push_front(temp);
					dq[j].pop_back();
				}
			}
			else {
				for (int l = 0; l < k; ++l) {
					temp = dq[j].front();
					dq[j].push_back(temp);
					dq[j].pop_front();
				}
			}
		}
		bool check = false;
		for (int a = 1; a <= n; ++a) {
			for (int b = 0; b < m; ++b) {
				if (dq[a][b] == 0)continue;
				bool temp_check = false;
				int temp_val = dq[a][b];
				q.push(make_pair(a, b));
				while (!q.empty()) {
					int r = q.front().first;
					int c = q.front().second;
					q.pop();

					for (int x = 0; x < 4; ++x) {
						int nr = r + dr[x];
						int nc = c + dc[x];
						if (nc == -1) nc = m - 1;
						else if (nc == m) nc = 0;
						if (nr <= 0 || nr > n || dq[nr][nc] == 0)continue;

						if (temp_val == dq[nr][nc]) {
							check = true;
							temp_check = true;
							dq[nr][nc] = 0;
							q.push(make_pair(nr, nc));
						}
					}
					if (temp_check == true)dq[r][c] = 0;
				}
			}
		}
		if (check == false) {
			int temp_cnt = 0;
			float temp_sum = 0;
			for (int a = 1; a <= n; ++a) {
				for (int b = 0; b < m; ++b) {
					if (dq[a][b] == 0)continue;
					temp_sum += dq[a][b];
					temp_cnt++;
				}
			}
			temp_sum = temp_sum / temp_cnt;
			for (int a = 1; a <= n; ++a) {
				for (int b = 0; b < m; ++b) {
					if (dq[a][b] == 0)continue;
					if (dq[a][b] > temp_sum) dq[a][b]--;
					else if (dq[a][b] < temp_sum) dq[a][b]++;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < m; ++j)
			ret += dq[i][j];
	cout << ret;
	return 0;
}