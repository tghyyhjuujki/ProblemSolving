#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
int ret, n, m;
int check[50][50];
string str[50];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
queue<pair<int, int> > q;

void bfs(int a, int b) {
	q.push({ a,b });
	check[a][b] = 1;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m || str[nr][nc] =='W' || check[nr][nc] != 0)continue;
			check[nr][nc] = check[r][c] + 1;
			if (ret < check[nr][nc]) ret = check[nr][nc] - 1;
			q.push({ nr,nc });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> str[i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (str[i][j] == 'L') {
				bfs(i, j);
				memset(check, 0, sizeof(check));
			}

	cout << ret << '\n';
	return 0;
}