#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int ret = 0, m, n;
int arr[300][300];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

struct ICE {
	int r, c, k;
};
queue<ICE> q;

int bfs() {
	int t = 0;
	while (!q.empty()) {
		t++;
		int size = q.size();
		while (size--) {
			int r = q.front().r;
			int c = q.front().c;
			int k = q.front().k;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (arr[nr][nc] > 0)continue;
				k--;
			}
			if (k > 0) q.push({ r,c,k });
		}
		memset(arr, 0, sizeof(arr));

		//새 맵 그리고
		int size3 = q.size();
		while (size3--) {
			int r = q.front().r;
			int c = q.front().c;
			int k = q.front().k;
			q.push({ r,c,k });
			q.pop();
			arr[r][c] = k;
		}

		//맵 하나 시작으로 맵 지우기
		queue<pair<int, int> > qq;
		qq.push({ q.front().r ,q.front().c});
		arr[q.front().r][q.front().c] = 0;
		while (!qq.empty()) {
			int r = qq.front().first;
			int c = qq.front().second;
			qq.pop();
			for (int i = 0; i < 4; ++i) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (arr[nr][nc] == 0) continue;
				arr[nr][nc] = 0;
				qq.push({ nr,nc });
			}
		}
		
		//검사하면서 1년후 맵 다시 그리기
		int size2 = q.size();
		for (int i = 0; i < size2; ++i) {
			int r = q.front().r;
			int c = q.front().c;
			int k = q.front().k;
			if (arr[r][c] == 0) {
				arr[r][c] = k;
				q.push({ r,c,k });
				q.pop();
			}
			else return t;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] > 0)q.push({ i,j,arr[i][j] });
		}
	}
	cout << bfs();
	return 0;
}