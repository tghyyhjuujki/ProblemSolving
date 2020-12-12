#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, ret = 0, s = 2, cnt = 0;
int arr[20][20], check[20][20];
int dr[4] = { 0,0,1,-1 }, dc[4] = { 1,-1,0,0 };

struct SHARK{
	int r, c;
}shark;
queue<pair<int,int> > q;
priority_queue<SHARK> pq;
bool operator<(SHARK a, SHARK b) {
	if (a.r == b.r) return a.c > b.c;
	return a.r > b.r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				q.push({ i,j });
				arr[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr < 0 || nc < 0 || nr >= n || nc >= n || arr[nr][nc]>s
					|| check[nr][nc] != 0)continue;
				check[nr][nc] = check[r][c] + 1;
				q.push({ nr,nc });
				if (arr[nr][nc] != 0 && arr[nr][nc] < s) pq.push({ nr,nc });
			}
		}
		if (pq.size() > 0) {
			cnt++;
			if (cnt == s) {
				s++;
				cnt = 0;
			}
			int r = pq.top().r;
			int c = pq.top().c;
			ret += check[r][c];
			arr[r][c] = 0;
			while (!q.empty())q.pop();
			q.push({ r,c });
			while (!pq.empty())pq.pop();
			memset(check, 0, sizeof(check));
		}
	}
	cout << ret;
	return 0;
}