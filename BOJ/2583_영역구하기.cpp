#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[100][100];
int m, n, k, x11, y11, x22, y22;
int temp = 0, ret = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<int> v;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[ny][nx] == 0) {
			arr[ny][nx] = 1;
			temp++;
			dfs(nx, ny);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x11 >> y11 >> x22 >> y22;
		for (int j = y11; j < y22; j++) {
			for (int l = x11; l < x22; l++) {
				arr[j][l] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 5) {
				i = 0; j = 5;
			}
			if (arr[i][j] == 0) {
				arr[i][j] = 1; temp++;
				dfs(j, i);
				v.push_back(temp);
				temp = 0;
				ret++;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << ret << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	return 0;
}