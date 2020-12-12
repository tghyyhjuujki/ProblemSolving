#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int ret = 0, R, C, m;
int arr[100][100];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,1,-1 };

struct SHARK {
	int r, c, s, d, z;
}sh;
vector<SHARK> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C >> m;
	memset(arr, -1, sizeof(arr));

	int mr = (R - 1) * 2;
	int mc = (C - 1) * 2;
	for (int i = 0; i < m; ++i) {
		cin >> sh.r >> sh.c >> sh.s >> sh.d >> sh.z;
		sh.r--; sh.c--; sh.d--;
		if (sh.d == 0 || sh.d == 1)sh.s = sh.s%mr;
		else if (sh.d == 2 || sh.d == 3)sh.s = sh.s%mc;
		v.push_back(sh);
		arr[sh.r][sh.c] = i;
	}
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < R; ++j) {
			if (arr[j][i] != -1) {
				ret += v[arr[j][i]].z;
				v[arr[j][i]].d = -1;
				arr[j][i] = -1;
				break;
			}
		}
		memset(arr, -1, sizeof(arr));
		for (int j = 0; j < m; ++j) {
			if (v[j].d == -1)continue;
			int r = v[j].r;
			int c = v[j].c;
			int d = v[j].d;
			int s = v[j].s;
			int z = v[j].z;
			while (s--) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if (nr < 0 || nc < 0 || nr >= R || nc >= C) {
					if (d == 0) d = 1;
					else if (d == 1) d = 0;
					else if (d == 2) d = 3;
					else if (d == 3) d = 2;
				}
				r += dr[d];
				c += dc[d];
			}
			v[j].r = r; v[j].c = c; v[j].d = d;
			if (arr[r][c] != -1) {
				if (v[arr[r][c]].z < z) {
					v[arr[r][c]].d = -1;
					arr[r][c] = j;
				}
				else v[j].d = -1;
			}
			else arr[r][c] = j;
		}
	}
	cout << ret;
	return 0;
}