#include<iostream>
#include<algorithm>
using namespace std;

int arr[500][500];
int check[500][500];

int n, m, ret = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int r, int c, int depth) {
	if (depth == 4) {
		return arr[r][c];
	}

	int temp = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dy[i];
		int nc = c + dx[i];
		if (0 <= nr && nr < n && 0 <= nc && nc < m && check[nr][nc] != 1) {
			check[nr][nc] = 1;
			temp = max(temp, arr[r][c] + dfs(nr, nc, depth + 1));
			check[nr][nc] = 0;
		}
	}

	return temp;
}

int  fuckyou(int r, int c) {
	int temp = 0;
	//ㅓ
	if (r >= 1 && c >= 1 && r < n - 1) {
		temp = max(temp, arr[r][c] + arr[r - 1][c] + arr[r][c - 1] + arr[r + 1][c]);
	}
	//ㅗ
	if (r >= 1 && c >= 1 && c < m - 1) {
		temp = max(temp, arr[r][c] + arr[r - 1][c] + arr[r][c - 1] + arr[r][c + 1]);
	}
	//ㅏ
	if (r >= 1 && r < n - 1 && c < m - 1) {
		temp = max(temp, arr[r][c] + arr[r - 1][c] + arr[r][c + 1] + arr[r + 1][c]);
	}
	//ㅜ
	if (c >= 1 && r < n - 1 && c < m - 1) {
		temp = max(temp, arr[r][c] + arr[r][c + 1] + arr[r][c - 1] + arr[r + 1][c]);
	}

	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = 1;
			if (i == 2 && j == 1) {
				i = 2; j = 1;
			}
			ret = max(ret, dfs(i, j, 1));
			ret = max(ret, fuckyou(i, j));
			check[i][j] = 0;
		}
	}

	cout << ret;

	return 0;
}