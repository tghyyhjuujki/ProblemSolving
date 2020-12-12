#include <iostream>
#include<vector>

using namespace std;
vector<vector<int> > arr;

int dir_x[4] = { 0,0,1,-1 };
int dir_y[4] = { 1,-1,0,0 };
int t, m, n, k, z = 0;

void dfs(int x, int y) {
	arr[x][y] = 0;
	for (int l = 0; l < 4; l++) {
		if (x + dir_x[l]>=0&& y + dir_y[l]>=0&&x + dir_x[l] < n &&
			y + dir_y[l] <m &&arr[x + dir_x[l]][y + dir_y[l]]==1) {
			dfs(x + dir_x[l], y + dir_y[l]);
		}
	}
}

int main() {
	cin >> t;
	for (int h = 0; h < t; h++) {
		cin >> m >> n >> k;
		arr.assign(n, vector<int>(m));
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					dfs(i,j);
					z++;
				}
			}
		}
		cout << z << "\n";
		z = 0;
	}
	return 0;
}