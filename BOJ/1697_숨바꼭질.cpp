#include <iostream>
#include<queue>
using namespace std;
int arr[200002];
int arr_check[200002];

int bfs(int n, int k) {
	int t = 0;
	arr_check[n] = 1;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		if (q.front() == k) {
			t = arr[q.front()];
			break;
		}
		int n_minus = q.front() - 1;
		int n_plus = q.front() + 1;
		int n_multiple = q.front() * 2;
		if (arr_check[n_minus] == 0&&n_minus>=0) {
			arr_check[n_minus] = 1;
			arr[n_minus] = arr[q.front()] + 1;
			q.push(n_minus);
		}
		if (arr_check[n_plus] == 0&&n_plus>=0) {
			arr_check[n_plus] = 1;
			arr[n_plus] = arr[q.front()] + 1;
			q.push(n_plus);
		}
		if (arr_check[n_multiple] == 0&& n_multiple>=0&& n_multiple<=100001) {
			arr_check[n_multiple] = 1;
			arr[n_multiple] = arr[q.front()] + 1;
			q.push(n_multiple);
		}
		q.pop();
	}
	return t;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k);
	return 0;
}
