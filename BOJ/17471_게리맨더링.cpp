#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n, ret = 10000;
int cost[10], arr[10][10];
vector<int> v[2];
queue<int> q;

void update() {
	int check[10] = {};
	for (int i = 0; i < 2; ++i) {
		q.push(v[i].front());
		check[q.front()] = 1;
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			for (int j = 0; j < v[i].size(); ++j) {
				if (f == v[i][j] || check[v[i][j]] == 1 || arr[f][v[i][j]] != 1)continue;
				check[v[i][j]] = 1;
				q.push(v[i][j]);
			}
		}
	}
	for (int i = 0; i < n; ++i) 
		if (check[i] == 0) return;
	
	int sum1 = 0, sum2 = 0, temp;
	for (int i = 0; i < v[0].size(); ++i)
		sum1 += cost[v[0][i]];
	for (int i = 0; i < v[1].size(); ++i)
		sum2 += cost[v[1][i]];

	temp = abs(sum1 - sum2);
	if (ret > temp) ret = temp;
}

void dfs(int depth) {
	if (depth == n) {
		update();
		return;
	}

	for (int i = 0; i < 2; ++i) {
		v[i].push_back(depth);
		if (v[i].size() == n) {
			v[i].pop_back();
			continue;
		}
		dfs(depth + 1);
		v[i].pop_back();
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> cost[i];

	int t, t_c;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		for (int j = 0; j < t; ++j) {
			cin >> t_c;
			t_c--;
			arr[i][t_c] = 1;
			arr[t_c][i] = 1;
		}
	}

	dfs(0);
	if (ret == 10000)cout << -1;
	else cout << ret;
	return 0;
}