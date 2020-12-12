#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int ret = 100000, n;
int arr[100][100], check[100][100];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
queue<pair<int, int> > q;

void bfs() {
	while (!q.empty()) {
		int size = q.size();
		bool temp = false;
		while (size--) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr < 0 || nc < 0 || nr >= n || nc >= n || check[nr][nc] != 0)continue;
				if (arr[nr][nc] != 0 && ret > check[r][c]) {
					ret = check[r][c];
					temp = true;
				}
				check[nr][nc] = check[r][c] + 1;
				q.push({ nr,nc });
				
			}
		}
		if (temp == true) {
			while (!q.empty())q.pop();
			return;
		}
	}
}

void dfs(int r, int c) {
	for (int i = 0; i < 4; ++i) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= n || check[nr][nc] > 0 || arr[nr][nc] != 1)continue;
		arr[nr][nc] = 2;
		check[nr][nc] = 1;
		q.push({ nr,nc });
		dfs(nr, nc);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == 1 && check[i][j] == 0) {
				arr[i][j] = 2;
				check[i][j] = 1;
				q.push({ i,j });
				dfs(i, j);
				bfs();
				memset(check, 0, sizeof(check));
			}
		}
	}

	cout << ret - 1;
	return 0;
}