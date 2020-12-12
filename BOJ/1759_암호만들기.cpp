#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m, mother = 0, son = 0;
string alpha, ret;
bool check[15];

void dfs(int depth, int cnt) {
	if (depth == n) {
		if (mother >= 1 && son >= 2) {
			cout << ret << '\n';
		}
		return;
	}

	for (int i = cnt; i < m; ++i) {
		if (check[i] == true)continue;
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i'
			|| alpha[i] == 'o' || alpha[i] == 'u')
			mother++;
		else son++;
		check[i] = true;
		ret.push_back(alpha[i]);
		dfs(depth + 1, i + 1);
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i'
			|| alpha[i] == 'o' || alpha[i] == 'u')
			mother--;
		else son--;
		check[i] = false;
		ret.pop_back();
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	char temp;
	for (int i = 0; i < m; ++i) {
		cin >> temp;
		alpha.push_back(temp);
	}
	sort(alpha.begin(), alpha.end());
	dfs(0, 0);
	return 0;
}