//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 1000000
using namespace std;
int n, a, b, c;
int fenwick[MAX + 1];

void update(int i, int cnt) {
	for (; i <= MAX; i += i & -i) {
		fenwick[i] += cnt;
	}
}

int find(int i) {
	int res = 0;
	for (; i; i -= i & -i) {
		res += fenwick[i];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (a == 1) {
			int l = 1, r = MAX;
			for (; l < r; ) {
				int mid = l + r >> 1;
				int cnd = find(mid);
				if (cnd >= b) {
					r = mid;
				}
				else {
					l = mid + 1;
				}
			}
			update(l, -1);
			cout << l << '\n';
		}
		else {
			cin >> c;
			update(b, c);
		}
	}
}