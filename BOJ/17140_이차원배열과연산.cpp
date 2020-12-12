#include <iostream>
#include <queue>
using namespace std;

int ret = 0, r, c, aim_r, aim_c, k, m_r = 3, m_c = 3;
int arr[101][101];
struct R {
	int n, cnt;
};
priority_queue<R> pq;
bool operator<(R a, R b) {
	if (a.cnt == b.cnt)return a.n > b.n;
	return a.cnt > b.cnt;
}

int main() {
	cin >> aim_r >> aim_c >> k;
	for (int i = 1; i < 4; ++i)
		for (int j = 1; j < 4; ++j)
			cin >> arr[i][j];

	int temp = 101;
	while (temp--) {
		if (arr[aim_r][aim_c] == k)break;
		r = m_r; c = m_c;
		if (r >= c) {
			for (int i = 1; i <= r; ++i) {
				int check[101] = {};
				for (int j = 1; j <= c; ++j) {
					check[arr[i][j]]++;
					arr[i][j] = 0;
				}
				for (int j = 1; j <= 100; ++j) {
					if (check[j] == 0)continue;
					pq.push({ j, check[j] });
				}
				for (int j = 1; j <= 101; j += 2) {
					if (pq.size() == 0)break;
					arr[i][j] = pq.top().n;
					arr[i][j + 1] = pq.top().cnt;
					pq.pop();
					if (m_c < j + 1)m_c = j + 1;
				}
				while (!pq.empty())pq.pop();
			}
		}

		else {
			for (int i = 1; i <= c; ++i) {
				int check[101] = {};
				for (int j = 1; j <= r; ++j) {
					check[arr[j][i]]++;
					arr[j][i] = 0;
				}
				for (int j = 1; j <= 100; ++j) {
					if (check[j] == 0)continue;
					pq.push({ j, check[j] });
				}
				for (int j = 1; j <= 101; j += 2) {
					if (pq.size() == 0)break;
					arr[j][i] = pq.top().n;
					arr[j + 1][i] = pq.top().cnt;
					pq.pop();
					if (m_r < j + 1)m_r = j + 1;
				}
				while (!pq.empty())pq.pop();
			}
		}
		ret++;
	}
	if (temp == -1)cout << -1;
	else cout << ret;
	return 0;
}