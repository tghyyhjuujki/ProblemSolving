#include <iostream>
using namespace std;

int n, z = 0, a[16][16], dr[3] = { 0,1,1 }, dc[3] = { 1,1,0 };

void f(int w, int r, int c, int d) {
	if (r == n - 1 && c == n - 1) {
		z++;
		return;
	}

	for (int i = 0; i < 3; ++i) {
		int y = r + dr[i], x = c + dc[i];
		if (y < 0 || x < 0 || y >= n || x >= n || a[y][x] != 0)continue;
		if (d == 0 && i == 2)continue;
		if (d == 2 && i == 0)continue;
		if (i == 1 && (a[y][c] != 0 || a[r][x] != 0)) continue;
		f(w + 1, y, x, i);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];
	f(0, 0, 1, 0);

	cout << z;
	return 0;
}