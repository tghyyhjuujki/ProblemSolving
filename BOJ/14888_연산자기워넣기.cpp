#include <iostream>
#include <vector>
using namespace std;
int n, max_val = -0x12341234, low_val = 0x12341234;
int a[11], oper_4[4]; // + - * /
vector<int> v;

void update() {
	int value = a[0];
	for (int i = 0; i < n - 1; ++i) {
		if (v[i] == 0) {
			value += + a[i + 1];
		}
		if (v[i] == 1) {
			value -= +a[i + 1];
		}
		if (v[i] == 2) {
			value *= +a[i + 1];
		}
		if (v[i] == 3) {
			value /= +a[i + 1];
		}
	}
	if (max_val < value)max_val = value;
	if (low_val > value)low_val = value;
}

void dfs(int depth) {

	if (depth == n - 1) {
		update();
		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (oper_4[i] == 0) continue;
		oper_4[i]--;
		v.push_back(i);
		dfs(depth + 1);
		v.pop_back();
		oper_4[i]++;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> oper_4[i];
	}
	dfs(0);
	cout << max_val << '\n' << low_val;
	return 0;
}