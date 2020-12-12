#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int ret = 0, n, m, k;
int A[10][10], arr[10][10];
int dr[8] = { -1,-1,-1,0,0,1,1,1 }, dc[8] = { -1,0,1,-1,1,-1,0,1 };
deque<int> tree[10][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> A[i][j];
			arr[i][j] = 5;
		}
	}
	int t1, t2, t3;
	for (int i = 0; i < m; ++i) {
		cin >> t1 >> t2 >> t3;
		t1--; t2--;
		tree[t1][t2].push_back(t3);
	}
	while (k--) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (tree[i][j].size() > 0) {
					int size = tree[i][j].size(), temp, temp2 = 0;
					for (int l = 0; l < size; ++l) {
						if (arr[i][j] >= tree[i][j].front()) {
							arr[i][j] -= tree[i][j].front();
							tree[i][j].front()++;
							temp = tree[i][j].front();
							tree[i][j].push_back(temp);
							tree[i][j].pop_front();
						}
						else {
							temp2 += tree[i][j].front() / 2;
							tree[i][j].pop_front();
						}
					}
					arr[i][j] += temp2;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int size = tree[i][j].size();
				for (int l = 0; l < size; ++l) {
					if (tree[i][j][l] % 5 == 0) {
						for (int o = 0; o < 8; ++o) {
							int r = i + dr[o];
							int c = j + dc[o];
							if (r < 0 || c < 0 || r >= n || c >= n)continue;
							tree[r][c].push_front(1);
						}
					}
				}
			}
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) 
				arr[i][j] += A[i][j];

	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ret += tree[i][j].size();

	cout << ret;
	return 0;
}