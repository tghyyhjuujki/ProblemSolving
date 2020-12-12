#include <iostream>
#include <queue>
using namespace std;
int ret = 1, n;
int arr[100][100];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
queue<pair<int, int> > q;

void update(int rain_high) {
	int check[100][100] = {};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] <= rain_high) check[i][j] = 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (check[i][j] == 1) continue;
			check[i][j] = 1;
			cnt++;
			q.push({ i,j });
			while (!q.empty()) {
				int r = q.front().first;
				int c = q.front().second;
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int nr = r + dr[i];
					int nc = c + dc[i];
					if (nr < 0 || nc < 0 || nr >= n || nc >= n || check[nr][nc] != 0)continue;
					check[nr][nc] = 1;
					q.push({ nr,nc });
				}
			}
		}
	}
	if (ret < cnt)ret = cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int temp_max = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (temp_max < arr[i][j]) temp_max = arr[i][j];
		}
	}
	for (int i = 1; i < temp_max; ++i) {
		update(i);
	}
	cout << ret;
	return 0;
}