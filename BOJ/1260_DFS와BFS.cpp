#include <iostream>
#include <queue>
#include<vector>
using namespace std;
int n, m, v;
vector<vector<int> > arr;
vector<int> arr_state;
queue<int> q;

void dfs(int idx) {
	arr_state[idx] = 1;
	cout << idx << " ";
	for (int i = 1; i <= n; i++) {
		if (arr[idx][i] && !arr_state[i]) {
			dfs(i);
		}
	}
}

void bfs(int idx) {
	arr_state[idx] = 0;
	q.push(idx);
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		cout << idx << " ";
		for (int i = 1; i <= n; i++) {
			if (arr[idx][i] && arr_state[i]) {
				arr_state[i] = 0;
				q.push(i);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> v;
	arr_state.assign(n + 1, 0);
	arr.assign(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		int front, end;
		cin >> front >> end;
		arr[front][end] = arr[end][front] = 1;
	}
	dfs(v);
	cout << "\n";
	bfs(v);
	return 0;
}