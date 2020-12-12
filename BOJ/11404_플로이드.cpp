#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000;
int arr[101][101];
int n, m;

void f() {
	for (int i = 1; i <= n; ++i) {
		for (int from = 1; from <= n; ++from) {
			if (arr[from][i] == 0)
				continue;
			for (int to = 1; to <= n; ++to) {
				if (arr[i][to] == 0 || from == to)
					continue;
				if (arr[from][to] == 0 || arr[from][to] >= arr[from][i] + arr[i][to])
					arr[from][to] = arr[from][i] + arr[i][to];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (!arr[from][to])
			arr[from][to] = cost;
		else
			arr[from][to] = min(arr[from][to], cost);
	}
	f();

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
	return 0;
}