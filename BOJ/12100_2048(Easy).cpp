#include <iostream>
#include <cstring>
using namespace std;
int ret, n;
int arr[20][20], m_check[20][20];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

void cp(int a1[20][20], int a2[20][20]) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a1[i][j] = a2[i][j];
}

void update2(int r, int c, int d) {
	if (arr[r][c] > 0) {
		int nr = r, nc = c;
		bool check = false;
		while (1) {
			nr += dr[d];
			nc += dc[d];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
				if (check == true) {
					arr[nr - dr[d]][nc - dc[d]] = arr[r][c];
					arr[r][c] = 0;
				}
				return;
			}
			if (arr[nr][nc] > 0) {
				if (arr[nr][nc] == arr[r][c] && m_check[nr][nc] == 0) {
					arr[nr][nc] *= 2;
					arr[r][c] = 0;
					m_check[nr][nc] = 1;
				}
				else {
					if (check == true) {
						arr[nr - dr[d]][nc - dc[d]] = arr[r][c];
						arr[r][c] = 0;
					}
				}
				return;
			}
			check = true;
		}
	}
}

void update(int d) {
	if (d == 1 || d == 3) {
		for (int r = 0; r < n; ++r)
			for (int c = 0; c < n; ++c)
				if (arr[r][c] > 0) update2(r, c, d);
	}

	else if (d == 0 || d == 2) {
		for (int r = n - 1; r >= 0; --r)
			for (int c = n - 1; c >= 0; --c)
				if (arr[r][c] > 0) update2(r, c, d);
	}
}

void dfs(int depth) {
	if (depth == 5) {
		int temp = 0;
		for (int r = 0; r < n; ++r)
			for (int c = 0; c < n; ++c)
				if (arr[r][c] > temp)temp = arr[r][c];

		if (temp > ret)ret = temp;
		return;
	}
	int arr_temp[20][20];
	for (int i = 0; i < 4; ++i) {
		cp(arr_temp, arr);
		memset(m_check, 0, sizeof(m_check));
		update(i);
		dfs(depth + 1);
		cp(arr, arr_temp);
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

	dfs(0);
	cout << ret;
	return 0;
}