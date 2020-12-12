#include <iostream>
using namespace std;

int ret = 30, temp = 0;
int arr[10][10], check_s[5] = { 5,5,5,5,5 };

void cp(int r, int c, int w, int zeroOne) {
	for (int i = r; i <= r+w; ++i)
		for (int j = c; j <= c+w; ++j)
			arr[i][j] = zeroOne;
}

bool check(int r, int c, int w) {
	for (int i = r; i <= r + w; ++i) {
		for (int j = c; j <= c + w; ++j) {
			if (i >= 10 || j >= 10) return false;
			if (arr[i][j] == 0)return false;
		}
	}
	return true;
}

void dfs(int depth, int r, int c) {
	for (int i = r; i < 10; ++i) {
		for (int j = c; j < 10; ++j) {
			for (int k = 4; k >= 0; --k) {
				if (arr[i][j] != 1) break;
				if (check_s[k] == 0)continue;
				if (check(i, j, k) == false) return;
				cp(i, j, k, 0);
				temp++;
				check_s[k]--;
				dfs(depth + 1, i, j);
				cp(i, j, k, 1);
				temp--;
				check_s[k]++;
			}
		}
		c = 0;
	}
	if (ret > temp) ret = temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			cin >> arr[i][j];
	dfs(0,0,0);
	if (ret == 30) cout << -1;
	else cout << ret;
	return 0;
}