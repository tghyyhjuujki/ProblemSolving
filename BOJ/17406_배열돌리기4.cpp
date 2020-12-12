#include<iostream>
#include<vector>
using namespace std;

int n, m, k, ret = 1000000;
int arr[50][50], rota[6][3], check[6];
int dr[4] = { -1,0,1,0 }, dc[4] = { 0,-1,0,1 };
vector<int> v;

void cp(int a[50][50], int b[50][50]) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = b[i][j];
}

void update(int x) {
	int c_r = rota[x][0];
	int c_c = rota[x][1];
	int s = rota[x][2];
	int temp;
	for (int i = 1; i <= s; ++i) {
		int r = c_r + i;
		int c = c_c + i;
		int d = 0;
		temp = arr[r][c];
		while (1) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr == c_r + i&& nc == c_c + i) {
				arr[r][c] = temp;
				break;
			}
			else arr[r][c] = arr[nr][nc];
			r = nr; c = nc;
			if ((nr == c_r - i && nc == c_c + i)
				|| (nr == c_r - i && nc == c_c - i)
				|| (nr == c_r + i && nc == c_c - i))d++;
		}
	}
}

void dfs(int depth) {
	if (depth == k) {
		for (int i = 0; i < n; ++i) {
			int temp = 0;
			for (int j = 0; j < m; ++j)
				temp += arr[i][j];
			if (temp < ret) ret = temp;
		}
		return;
	}

	int arr_temp[50][50];
	for (int i = 0; i < k; ++i) {
		if (check[i] == 1)continue;
		cp(arr_temp, arr);
		v.push_back(i);
		check[i] = 1;
		update(i);
		dfs(depth + 1);
		v.pop_back();
		check[i] = 0;
		cp(arr, arr_temp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];
	
	for (int i = 0; i < k; ++i) {
		cin >> rota[i][0] >> rota[i][1] >> rota[i][2];
		rota[i][0]--; rota[i][1]--;
	}
	dfs(0);
	cout << ret;
	return 0;
}