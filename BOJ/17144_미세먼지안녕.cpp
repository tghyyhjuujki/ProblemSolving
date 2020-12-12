//#define _CRT_SECRUE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int ar, ac, t, air_up_r, air_down_r, ret = 0;
bool check = true;
int arr[50][50];
int temp[50][50];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

queue<pair<int, int> > q;

void upRo(int ur, int uc, int ro) {
	int nur = ur + dr[ro % 4];
	int nuc = uc + dc[ro % 4];
	if (nur == air_up_r && nuc == 0) {
		temp[ur][uc] = 0;
		return;
	}
	if (nur < 0 || nur > air_up_r || nuc < 0 || nuc >= ac) {
		upRo(ur, uc, ro + 1);
		return;
	}
	temp[ur][uc] = temp[nur][nuc];
	upRo(nur, nuc, ro);
}

void downRo(int dor, int doc, int ro) {

	int ndor = dor + dr[(ro + 3) % 4];
	int ndoc = doc + dc[(ro + 3) % 4];
	if (ndor == air_down_r && ndoc == 0) {
		temp[dor][doc] = 0;
		return;
	}
	if (ndor < air_down_r || ndor >= ar || ndoc < 0 || ndoc >= ac) {
		downRo(dor, doc, ro + 3);
		return;
	}
	temp[dor][doc] = temp[ndor][ndoc];
	downRo(ndor, ndoc, ro);
}

void bfs() {
	while (t--) {
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				int r = q.front().first;
				int c = q.front().second;
				int cnt = 0;
				q.pop();

				for (int i = 0; i < 4; ++i) {
					int nr = r + dr[i];
					int nc = c + dc[i];
					if (nr < 0 || nc < 0 || nr >= ar || nc >= ac || arr[nr][nc] == -1) continue;
					temp[nr][nc] += (int)arr[r][c] / 5;
					cnt++;
				}

				temp[r][c] = temp[r][c] + arr[r][c] - ((int)arr[r][c] / 5)*cnt;

			}
		}
		upRo(air_up_r - 1, 0, 0);
		downRo(air_down_r + 1, 0, -1);
		for (int i = 0; i < ar; ++i) {
			for (int j = 0; j < ac; ++j) {
				arr[i][j] = temp[i][j];
				if (temp[i][j] > 0) q.push({ i,j });
				temp[i][j] = 0;
			}
		}
		arr[air_up_r][0] = -1; arr[air_down_r][0] = -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> ar >> ac >> t;
	for (int i = 0; i < ar; ++i) {
		for (int j = 0; j < ac; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == -1 && check == true) {
				air_up_r = i;
				air_down_r = i + 1;
				check = false;
			}
			else if (arr[i][j] > 0) {
				q.push({ i,j });
			}
		}
	}
	bfs();
	for (int i = 0; i < ar; ++i) {
		for (int j = 0; j < ac; ++j) {
			if (arr[i][j] > 0) {
				ret += arr[i][j];
			}
		}
	}
	cout << ret;
	return 0;
}