#include <iostream>
#include <queue>
#include <string>
using namespace std;
int ret, m, n;
string str[50];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
queue<pair<int, int> > b;
queue<pair<int, int> > water;

int bfs() {
	int t = 0;
	while (water.size() > 0 || b.size() > 0) {
		t++;
		int sw = water.size();
		while (sw--) {
			int r = water.front().first;
			int c = water.front().second;
			water.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr < 0 || nc < 0 || nr >= n || nc >= m || 
					str[nr][nc] == 'X' || str[nr][nc] == 'D' || str[nr][nc] == '*')continue;
				str[nr][nc] = '*';
				water.push({ nr,nc });
			}
		}
		int sb = b.size();
		while (sb--) {
			int r = b.front().first;
			int c = b.front().second;
			b.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr < 0 || nc < 0 || nr >= n || nc >= m ||
					str[nr][nc] == 'X' || str[nr][nc] == '*' || str[nr][nc] == 'S')continue;
				if (str[nr][nc] == 'D') return t;
				str[nr][nc] = 'S';
				b.push({ nr,nc });
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> str[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (str[i][j] == 'S') b.push({ i,j });
			else if (str[i][j] == '*')water.push({ i,j });
		}
	}
	ret = bfs();
	if (ret == -1)cout << "KAKTUS";
	else cout << ret;
	return 0;
}