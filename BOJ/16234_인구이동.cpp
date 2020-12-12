#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int ret = 0, n, L, R;
int arr[50][50], check[50][50] = {};
int dr[4] = { 0,0,1,-1 }, dc[4] = { 1,-1,0,0 };
queue<pair<int, int> > q;
vector<vector<pair<int, int> > > v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> L >> R;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	while (1) {
		bool tc = false;
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b) {
				if (check[a][b] != 0) continue;
				q.push({ a,b });
				vector<pair<int, int> > tv;
				tv.push_back({ a,b });
				bool tc2 = false;
				while (!q.empty()) {
					check[a][b] = 1;
					int r = q.front().first;
					int c = q.front().second;
					q.pop();
					for (int i = 0; i < 4; ++i) {
						int nr = r + dr[i];
						int nc = c + dc[i];
						if (nr < 0 || nc < 0 || nr >= n || nc >= n || check[nr][nc] != 0)continue;
						if (abs(arr[r][c] - arr[nr][nc]) < L || abs(arr[r][c] - arr[nr][nc]) > R)continue;
						check[nr][nc] = 1;
						q.push({ nr,nc });
						tv.push_back({ nr,nc });
						tc = true; tc2 = true;
					}
				}
				if (tc2 == true)
					v.push_back(tv);
			}
		}
		if (tc == true) {	
			for (int i = 0; i < v.size(); ++i) {
				int temp = v[i].size(), temp2 = 0;
				for (int j = 0; j < v[i].size(); ++j) 
					temp2 += arr[v[i][j].first][v[i][j].second];
				temp2 = temp2 / temp;
				for (int j = 0; j < temp; ++j)
					arr[v[i][j].first][v[i][j].second] = temp2;
			}
			ret++;
		}
		else break;
		memset(check, 0, sizeof(check));
		while (!v.empty())v.pop_back();
	}


	cout << ret;
	return 0;
}