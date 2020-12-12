#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ret = 100000, cnt = 1, length = 0, cnt_land;
int arr[10][10], land[10], check_land[7][7];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
queue<pair<int, int> > q;

void map_cp(int arr1[7][7], int arr2[7][7]) {
	for (int i = 1; i < cnt_land; ++i)
		for (int j = 1; j < cnt_land; ++j)
			arr1[i][j] = arr2[i][j];
}

void dfs(int depth, int r, int c, int d) {
	if (depth == cnt_land - 2) {
		int check[7] = {};
		queue<int> qq;
		qq.push(1);
		check[1] = 1;
		while (!qq.empty()) {
			int f = qq.front();
			qq.pop();
			for (int i = 1; i < cnt_land; ++i) {
				if (check[i] == 0 && check_land[f][i] == 1) {
					check[i] = 1;
					qq.push(i);
				}
			}
		}
		for (int i = 1; i < cnt_land; ++i)
			if (check[i] == 0)return;
		if (length != 0 && ret > length) ret = length;
		return;
	}

	int temp_land[7][7];
	for (int i = r; i < n; ++i) {
		for (int j = c; j < m; ++j) {
			if (arr[i][j] == 0) continue;
			map_cp(temp_land, check_land);
			for (int k = d; k < 4; ++k) {
				cnt = arr[i][j];
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (nr < 0 || nc < 0 || nr >= n || nc >= m || arr[nr][nc] != 0)continue;
				int temp = 0;
				int nnr = nr;
				int nnc = nc;
				bool check = false;
				while (1) {
					nnr += dr[k];
					nnc += dc[k];
					if (nnr < 0 || nnc < 0 || nnr >= n || nnc >= m || 
						check_land[cnt][arr[nnr][nnc]] == 1)break;
					if (arr[nnr][nnc] != 0) {
						temp = abs(i - nnr + j - nnc) - 1;
						if (temp < 2)break;
						check_land[cnt][arr[nnr][nnc]] = 1;
						check_land[arr[nnr][nnc]][cnt] = 1;
						check = true;
						break;
					}
				}
				if (check == false) continue;
				length += temp;
				dfs(depth + 1, i, j, k + 1);
				length -= temp;
				map_cp(check_land, temp_land);
			}
			d = 0;
		}
		c = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)arr[i][j] = -1;
		}
	}

	cnt_land = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == -1) {
				q.push({ i,j });
				while (!q.empty()) {
					int r = q.front().first;
					int c = q.front().second;
					arr[r][c] = cnt_land;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						int nr = r + dr[k];
						int nc = c + dc[k];
						if (nr < 0 || nc < 0 || nr >= n || nc >= m || arr[nr][nc] != -1) continue;
						arr[nr][nc] = cnt_land;
						q.push({ nr,nc });
					}
				}
				cnt_land++;
			}
		}
	}
	dfs(0, 0, 0, 0);
	if (ret == 100000) cout << -1;
	else cout << ret;
	return 0;
}