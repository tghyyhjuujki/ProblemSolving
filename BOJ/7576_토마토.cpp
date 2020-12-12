//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
using namespace std;
int arr[1001][1001];
int check[1001][1001];
int dir_r[4] = { 1,-1,0,0 };
int dir_c[4] = { 0,0,-1,1 };
queue<pair<int, int> > q;
int r, c;
bool a = false;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int m, n;
	cin >> m >> n;
	//m = c,n = r
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin>>arr[i][j];
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		check[r][c] = 1;
		int cur_r, cur_c;
		q.pop();
		for (int i = 0; i < 4; i++) {
			cur_r = r + dir_r[i];
			cur_c = c + dir_c[i];
			if (cur_r > 0 && cur_c > 0 && cur_r <= n && cur_c <= m&& arr[cur_r][cur_c]==0&&check[cur_r][cur_c]==0) {
				check[cur_r][cur_c] = 1;
				arr[cur_r][cur_c] = arr[r][c]+1;
				q.push(make_pair(cur_r, cur_c));
			}
		}
	}
	//i=행 j=열
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0) {
				a = true;
			}
		}
	}
	if (a == false) {
		cout << arr[r][c] - 1;
	}
	else cout << -1;
	return 0;
}
