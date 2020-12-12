#include <iostream>
#include <queue>
using namespace std;
int n, m, ret = 0;
int arr[50][50];
int dr[8] = { -1,-1,-1,0,0,1,1,1 };
int dc[8] = { -1,0,1,-1,1,-1,0,1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		cin >> m >> n;
		if (n == 0 && m == 0)break;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> arr[i][j];
		queue<pair<int, int> > q;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr[i][j] == 1) {
					ret++;
					arr[i][j] = 0;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						int r = q.front().first;
						int c = q.front().second;
						q.pop();
						for (int i = 0; i < 8; ++i) {
							int nr = r + dr[i];
							int nc = c + dc[i];
							if (nr < 0 || nc < 0 || nr >= n || nc >= m || arr[nr][nc] == 0)continue;
							q.push(make_pair(nr, nc));
							arr[nr][nc] = 0;
						}
					}
				}
			}
		}
		cout << ret << '\n';
		ret = 0;
	}
	return 0;
}