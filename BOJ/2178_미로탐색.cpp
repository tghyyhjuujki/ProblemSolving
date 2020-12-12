//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
int n, m;
int arr[101][101];
int arr_check[101][101];
int dir_x[4] = { 0,0,-1,1 };
int dir_y[4] = { 1,-1,0,0 };
string str;

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			if (nx<1 || nx>n || ny<1 || ny>m)
				continue;
			if (arr[nx][ny] == 1) {
				q.push(make_pair(nx,ny));
				arr[nx][ny] = arr[x][y] + 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		cin>>str;
		for (int j = 0; j < m; j++) {
			arr[i+1][j+1] = (int)str[j]-48;
		}
	}
	bfs(1, 1);
	cout << arr[n][m];
	return 0;
}
