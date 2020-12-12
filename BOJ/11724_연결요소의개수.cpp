//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int arr[1001][1001];
int check[1001];
int n, m, x = 0;

void dfs(int idx) {
	for (int i = 1; i <= n; i++) {
		if (arr[idx][i] == 1 && check[i] == 0) {
			check[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int u, v;
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		arr[u][v] = arr[v][u] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			x++;
			dfs(i);
		}
	}
	cout << x;
	return 0;
}