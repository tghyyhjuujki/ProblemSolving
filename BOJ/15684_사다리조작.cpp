#include <iostream>
using namespace std;
int n, ret = 10, m, h, max_val = 0;
int arr[31][21];

bool update() {
	int c;
	for (int j = 1; j < n * 2; j += 2) {
		c = j;
		int r = 0;
		bool check[31][21] = {};
		while (1) {
			if (check[r][c - 1] == 0 && arr[r][c - 1] == 1) {
				check[r][c - 1] = 1;
				c -= 2;
			}
			else if (check[r][c + 1] == 0 && arr[r][c + 1] == 1){
				check[r][c + 1] = 1;
				c += 2;
			}
			else r++;
			if (r == h) {
				if (c == j)break;
				else return false;
			}
		}
		if (j == (2 * n) - 1) return true;
	}
}

void dfs(int depth, int r, int c) {
	if (depth == max_val) {
		if (update() == true)ret = depth;
		return;
	}
	
	for (int i = r; i < h; ++i) {
		for (int j = c; j < 2 * n - 1; j += 2) {
			if (arr[i][j] != 0 || arr[i][j - 2] == 1 || arr[i][j + 2] == 1)continue;
			arr[i][j] = 1;
			arr[i][j - 2] = 2;
			arr[i][j + 2] = 2;
			dfs(depth + 1, i, j);
			arr[i][j] = 0;
			arr[i][j - 2] = 0;
			arr[i][j + 2] = 0;
		}
		c = 2;
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> h;
	for (int i = 0; i <= h; ++i)
		for (int j = 1; j < 2 * n; j += 2)
			arr[i][j] = 1;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		arr[--a][b * 2] = 1;
	}
	for (int i = 0; i <= 3; ++i) {
		max_val = i;
		dfs(0, 0, 2);
		if (ret != 10)break;
	}
	if (ret == 10)ret = -1;
	cout << ret;
	return 0;
}