#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int ret = 0;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int check[12][6];
string str[12];
vector<pair<int, int> > v;
queue<pair<int, int> > q;

void gravity(int r, int c) {
	char t = str[r][c];
	str[r][c] = '.';
	while (1) {
		if (r == 11 || str[r + 1][c] != '.') {
			str[r][c] = t;
			return;
		}
		else r++;
	}
}

int bfs() {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= 12 || nc >= 12 || 
				str[r][c] != str[nr][nc] || str[nr][nc] == '.' || check[nr][nc] != 0)continue;
			check[nr][nc] = 1;
			q.push({ nr,nc });
			v.push_back({ nr,nc });
		}
	}
	if (v.size() >= 4) {
		for (int i = 0; i < v.size(); ++i) {
			str[v[i].first][v[i].second] = '.';
		}
		return 1;
	}
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 12; ++i)
		cin >> str[i];
	while (1) {
		bool tri = false;
		for (int i = 11; i >= 0 ; --i) {
			for (int j = 0; j < 6; ++j) {
				if (str[i][j] != '.') {
					q.push({ i,j });
					check[i][j] = 1;
					v.push_back({ i,j });
					if (bfs() > 0) tri = true;
					v.clear();
				}
			}
		}
		memset(check, 0, sizeof(check));

		for (int i = 11; i >= 1; --i) {
			for (int j = 0; j < 6; ++j) {
				if (str[i][j] == '.' && str[i - 1][j] != '.') {
					gravity(i - 1, j);
				}
			}
		}

		if (tri == true) ret++;
		else break;
	}
	cout << ret;
	return 0;
}