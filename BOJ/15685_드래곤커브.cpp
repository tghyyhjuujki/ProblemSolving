#include<iostream>
#include<queue>

using namespace std;

struct dragon{
	int x, y;
};

int arr[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int asdf[11] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
queue<dragon> q;

int main() {
	dragon dra;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, y, x, d, g, cx, cy, ret=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		if (x == 4 && y == 2) {
			x = 4; y = 2;
		}
		dra.x = x; dra.y = y;
		q.push(dra);
		dra.x = x + dx[d]; dra.y = y + dy[d];
		cx = dra.x; cy = dra.y;
		q.push(dra);
		if (g > 0) {
			for (int i = 1; i <= g; i++) {
				int newx, newy;
				for (int j = 0; j <asdf[i]; j++) {
					q.push(q.front());
					int tempx = cx - q.front().x;
					int tempy = cy - q.front().y;
					q.pop();
					if (tempx != 0) {
						newy = cy - tempx;
					}
					else { newy = cy; }

					if (tempy != 0) {
						newx = cx + tempy;
					}
					else { newx = cx; }
					dra.x = newx; dra.y = newy;
						
					q.push(dra);
				}
				cx = newx; cy = newy;
			}
		}
		while (!q.empty()) {
			arr[q.front().y][q.front().x] = 1;
			q.pop();
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j]==1&&arr[i][j+1]==1&&arr[i+1][j]==1&&arr[i+1][j+1]==1) {
				ret++;
			}
		}
	}
	cout << ret;
	return 0;
}