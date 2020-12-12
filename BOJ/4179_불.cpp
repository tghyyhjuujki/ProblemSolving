#include <iostream>
#include <string>
#include <queue>
using namespace std;
int ret = 0, n, m;
string str[1000];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
struct RC { int r, c; };
queue<RC> f, q;

void bfs() {
	int t = 0;
	while (!q.empty()) {
		t++;
		int size1 = q.size();
		int size2 = f.size();
		while (size2--) {
			int r = f.front().r;
			int c = f.front().c;
			f.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr < 0 || nc < 0 || nr >= n || nc >= m)continue;
				if (str[nr][nc] == '#' || str[nr][nc] == 'F')continue;
				str[nr][nc] = 'F';
				f.push({ nr,nc });
			}
		}
		while (size1--) {
			int r = q.front().r;
			int c = q.front().c;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
					ret = t;
					return;
				}
				if (str[nr][nc] == '#' || str[nr][nc] == 'F' || str[nr][nc] == 'J') continue;
				str[nr][nc] = 'J';
				q.push({ nr,nc });
			}
		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
		for (int j = 0; j < m; ++j) {
			if (str[i][j] == 'J')q.push({ i,j });
			else if (str[i][j] == 'F')f.push({ i,j });
		}
	}
	bfs();
	if (ret == 0)cout << "IMPOSSIBLE";
	else cout << ret;
	return 0;
}