//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
using namespace std;
int arr[101][101][101];
int check[101][101][101];
int dir_d[6] = { 0,0,0,0,1,-1 };
int dir_r[6] = { 1,-1,0,0,0,0 };
int dir_c[6] = { 0,0,-1,1,0,0 };
queue<int> q_d;
queue<pair<int, int> > q;
int d, r, c;
bool a = false;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int m, n, h;
	cin >> m >> n >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for(int k=1;k<=m;k++){
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q_d.push(i);
					q.push(make_pair(j, k));
				}
			}
		}
	}
	while (!q.empty()) {
		d = q_d.front();
		r = q.front().first;
		c = q.front().second;
		check[d][r][c] = 1;
		int cur_d, cur_r, cur_c;
		q.pop();
		q_d.pop();
		for (int i = 0; i < 6; i++) {
			cur_d = d + dir_d[i];
			cur_r = r + dir_r[i];
			cur_c = c + dir_c[i];
			if (cur_d > 0 && cur_r > 0 && cur_c > 0 && cur_d <= h&& cur_r <= n 
				&& cur_c <= m&& arr[cur_d][cur_r][cur_c]==0&&check[cur_d][cur_r][cur_c]==0) {
				check[cur_d][cur_r][cur_c] = 1;
				arr[cur_d][cur_r][cur_c] = arr[d][r][c]+1;
				q_d.push(cur_d);
				q.push(make_pair(cur_r, cur_c));
			}
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for(int k=1;k<=m;k++){
				if (arr[i][j][k] == 0) {
					a = true;
				}
			}
		}
	}
	if (a == false) {
		cout << arr[d][r][c] - 1;
	}
	else cout << -1;
	return 0;
}