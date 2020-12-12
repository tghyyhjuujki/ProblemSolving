#include <iostream>
#include <queue>
using namespace std;
int ret = 0, t, n;
int arr[101][101], check[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t >> n;
	int a, b;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	int cnt = 0;
	queue<int> q;
	check[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int r = q.front();
		q.pop();
		for (int i = 1; i <= t; ++i) {
			if (arr[r][i] == 1 && check[i] == 0) {
				check[i] = 1;
				q.push(i);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}