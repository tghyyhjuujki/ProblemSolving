#include <iostream>
using namespace std;

int n, m, r, c, d, ret = 1;
int arr[50][50];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void Rotate(int r, int c, int d, int cnt) {
	if (cnt == 4) {
		if (arr[r + dr[(d + 2) % 4]][c + dc[(d + 2) % 4]] == 1) return;
		Rotate(r + dr[(d + 2) % 4], c + dc[(d + 2) % 4], d, 0);
		return;
	}

	int nr = r + dr[(d + 3) % 4];
	int nc = c + dc[(d + 3) % 4];

	if (arr[nr][nc] == 0) {
		arr[nr][nc] = ret + 1;
		if (arr[r][c] == 1) arr[r][c] = -1;
		if (arr[nr][nc] > ret) ret = arr[nr][nc];
		Rotate(nr, nc, (d + 3) % 4, 0);
	}
	else Rotate(r, c, (d + 3) % 4, cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	arr[r][c] = 1;
	Rotate(r, c, d, 0);

	cout << ret;
	return 0;
}