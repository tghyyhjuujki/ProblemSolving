#include <iostream>
using namespace std;
long long n, ret = 0, b, c;
long long a[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	ret += n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> b >> c;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= b) a[i] -= b;
		else a[i] = 0;
		int temp = a[i] % c;
		ret += a[i] / c;
		if (temp > 0) ret++;
	}
	cout << ret;
	return 0;
}