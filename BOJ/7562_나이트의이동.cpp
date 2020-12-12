#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int ret, t, l;
pair<int, int> np, aim;
int arr[300][300];
int dr[8] = { 2,2,1,1,-1,-1,-2,-2 };
int dc[8] = { -1,1,-2,2,-2,2,-1,1 };

void bfs(queue<pair<int, int> > q) {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= l || nc >= l || arr[nr][nc] > 0)continue;
			if (arr[nr][nc] == -1) {
				ret = arr[r][c];
				return;
			}
			arr[nr][nc] = arr[r][c] + 1;
			q.push({ nr,nc });
		}
	}
}

int main() {
	cin >> t;
	while (t--) {
		cin >> l;
		cin >> np.first >> np.second >> aim.first >> aim.second;
		arr[np.first][np.second] = 1;
		arr[aim.first][aim.second] = -1;
		queue<pair<int, int> > q;
		q.push({ np.first , np.second });
		ret = 0;
		if (np.first != aim.first || np.second != aim.second) bfs(q);
		memset(arr, 0, sizeof(arr));
		cout << ret << '\n';
	}
	return 0;
}