#include <iostream>
#include <string>
using namespace std;

string arr[20];
int n, m, ret = 0;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
bool check[26];

void dfs(int depth, int r,int c) {

	if (depth > ret) {
		ret = depth;
	}
	
	for (int i = 0; i < 4; ++i) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m)continue;
		if (check[arr[nr][nc] - 65] == true)continue;
		check[arr[nr][nc] - 65] = true;
		dfs(depth + 1, nr, nc);
		check[arr[nr][nc] - 65] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	check[arr[0][0] - 65] = true;
	dfs(1, 0, 0);
	cout << ret;
	return 0;
}