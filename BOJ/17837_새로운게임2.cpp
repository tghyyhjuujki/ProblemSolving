#include <iostream>
#include <vector>
using namespace std;

int n, ret = 0, k;
int arr[12][12], horse[10][4];
int dr[4] = { 0,0,-1,1 };
int dc[4] = { 1,-1,0,0 };
vector<int> ground[12][12];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	for (int i = 0; i < k; ++i) {
		cin >> horse[i][0] >> horse[i][1] >> horse[i][2];
		horse[i][0]--; horse[i][1]--; horse[i][2]--; horse[i][3] = 0;
		ground[horse[i][0]][horse[i][1]].push_back(i);
	}
	int cnt = 0;
	bool check = false;
	while (cnt < 1000) {
		cnt++;
		for (int i = 0; i < k; ++i) {
			int r = horse[i][0];
			int c = horse[i][1];
			int h_index = horse[i][3];
			int last_index = ground[r][c].size();
			int nr = r + dr[horse[i][2]];
			int nc = c + dc[horse[i][2]];

			if (nr < 0 || nc < 0 || nr >= n || nc >= n || arr[nr][nc] == 2) {
				if (horse[i][2]	 < 2)horse[i][2] = (horse[i][2] + 1) % 2;
				else horse[i][2] = (horse[i][2] + 1) % 2 + 2;
				nr = r + dr[horse[i][2]];
				nc = c + dc[horse[i][2]];
			}
			if (nr < 0 || nc < 0 || nr >= n || nc >= n || arr[nr][nc] == 2) continue;
			if (arr[nr][nc] == 1) {
				for (int j = h_index; j < last_index; ++j) {
					ground[nr][nc].push_back(ground[r][c].back());
					horse[ground[r][c].back()][3] = ground[nr][nc].size() - 1;
					horse[ground[r][c].back()][0] = nr; horse[ground[r][c].back()][1] = nc;
					ground[r][c].pop_back();
				}
			}
			else if (arr[nr][nc] == 0) {
				for (int j = h_index; j < last_index; ++j) {
					ground[nr][nc].push_back(ground[r][c][j]);
					horse[ground[r][c][j]][3] = ground[nr][nc].size() - 1;
					horse[ground[r][c][j]][0] = nr; horse[ground[r][c][j]][1] = nc;
				}
				for (int j = h_index; j < last_index; ++j)
					ground[r][c].pop_back();
			}
			if (ground[nr][nc].size() >= 4) {
				check = true;
				break;
			}
		}
		if (check == true)break;
		
	}
	if (cnt == 1000)cout << -1;
	else cout << cnt;
	return 0;
}