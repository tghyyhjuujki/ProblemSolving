#include <iostream>
#include <algorithm>
using namespace std;

int arr[20][20], check[20][20] = {};
int n;

int f() {
	int ret = 0;
	for (int from = 0; from < n; ++from) {
		for (int to = from; to < n; ++to) {
			for (int mid = 0; mid < n; ++mid) {
				if (arr[mid][to] == 0 || arr[mid][from] == 0)continue;
				if (arr[from][to] == arr[mid][from] + arr[mid][to]) {
					check[from][to] = 1;
					break;
				}
				else if (arr[from][to] > arr[mid][from] + arr[mid][to])
					return -1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (check[i][j] == 1) arr[i][j] = 0;
			if (arr[i][j] != 0)
				ret += arr[i][j];
		}
	}

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	cout << f();
	return 0;
}