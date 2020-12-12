#include <iostream>
#include <queue>
using namespace std;
int n, k, L;
int arr[100][100];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
queue<pair<int, char> > q;
queue<pair<int, int> > tail;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	int r, c;
	for (int i = 0; i < k; ++i) {
		cin >> r >> c;
		r--; c--;
		arr[r][c] = 2;
	}
	cin >> L;
	int x;
	char a;
	for (int i = 0; i < L; ++i) {
		cin >> x >> a;
		q.push({ x,a });
	}
	r = 0; c = 0;
	int d = 0, t = 0, nr = r, nc = c;
	arr[r][c] = 1;
	tail.push({ 0,0 });
	while (1) {
		t++;
		nr += dr[d];
		nc += dc[d];
		if (nr < 0 || nc < 0 || nr >= n || nc >= n || arr[nr][nc] == 1)break;
		if (arr[nr][nc] == 0) {
			arr[tail.front().first][tail.front().second] = 0;
			tail.pop();
		}
		tail.push({ nr,nc });
		arr[nr][nc] = 1;
		if (!q.empty()) {
			int limit = q.front().first;
			char lod = q.front().second;
			if (t != limit)continue;
			else {
				q.pop();
				if (lod == 'L') d = (d + 3) % 4;
				else d = (d + 1) % 4;
			}
		}
	}
	cout << t;
	return 0;
}