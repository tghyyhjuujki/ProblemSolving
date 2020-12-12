#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, ret = 0;
int arr[8][8];
//4방향 탐색할 변수
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0, };
queue<pair<int, int> > q;
vector<pair<int, int> > v;

//맵 카피함수
void map_cp(int arr1[8][8], int arr2[8][8]) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			arr1[i][j] = arr2[i][j];
}

//바이러스 퍼트리기
void bfs() {
	for (int i = 0; i < v.size(); ++i)
		q.push({ v[i].first, v[i].second });

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m || arr[nr][nc] != 0)continue;
			arr[nr][nc] = 2;
			q.push(make_pair(nr, nc));
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (arr[i][j] == 0)cnt++;

	if (ret < cnt) {
		ret = cnt;
	}
}

void dfs(int depth, int r, int c) {
	if (depth == 3) {
		bfs();
		return;
	}
	//기둥세우고 맵 저장,불러오기
	int map_temp[8][8];
	for (int i = r; i < n; ++i) {
		for (int j = c; j < m; ++j) {
			if (arr[i][j] != 0)continue;
			map_cp(map_temp, arr);
			arr[i][j] = 1;
			dfs(depth + 1, i, j);
			map_cp(arr, map_temp);
			arr[i][j] = 0;
		}
		//c=0해야 열의 처음부터 탐색함
		c = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	//맵 그리고 바이러스 v에 push
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)v.push_back({ i,j });
		}
	}

	dfs(0, 0, 0);
	cout << ret;
	return 0;
}