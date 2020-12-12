#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ret = 0, k, n, d;
int arr[4][8], check[4];
string str[4];

void rotate(int n, int d) {
	int temp, c3, c9;
	c3 = arr[n][2]; c9 = arr[n][6];
	if (d == 1) {
		temp = arr[n][7];
		for (int i = 7; i > 0; --i) {
			arr[n][i] = arr[n][i - 1];
		}
		arr[n][0] = temp;
	}
	else {
		temp = arr[n][0];
		for (int i = 0; i < 7; ++i) {
			arr[n][i] = arr[n][i + 1];
		}
		arr[n][7] = temp;
	}
	check[n] = 1;
	if (check[n+1] == 0 && n >= 0 && n < 3 && arr[n + 1][6] != c3) 
		rotate(n + 1, d * (-1));
	if (check[n-1] == 0 && n > 0 && n <= 3 && arr[n - 1][2] != c9) 
		rotate(n - 1, d * (-1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; ++i) {
		cin >> str[i];
	}
	
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 8; ++j) {
			arr[i][j] = (int)str[i][j] - 48;
		}
	}

	cin >> k;
	while (k--) {
		cin >> n >> d;
		rotate(n - 1, d);
		for (int i = 0; i < 4; ++i)
			check[i] = 0;
	}

	for (int i = 0; i < 4; ++i) {
		ret += arr[i][0] * pow(2, i);
	}

	cout << ret;
	return 0;
}