#include<iostream>
using namespace std;

struct CCTV {
	int type, r, c;
};
int n, m, ret, cctv_size=0;
int arr[8][8];
CCTV cctv[8];
int cctv_info[5] = { 4,2,4,4,1 };

void update(int dir, CCTV cctv){
	dir = (dir % 4);
	if (dir == 0) {
		for (int r = cctv.r-1; r >= 0; r--) {
			if (arr[r][cctv.c] == 6) break;
			arr[r][cctv.c] = -1;
		}
	}
	if (dir == 1) {
		for (int c = cctv.c-1; c >= 0; c--) {
			if (arr[cctv.r][c] == 6) break;
			arr[cctv.r][c] = -1;
		}
	}
	if (dir == 2) {
		for (int r = cctv.r+1; r < n; r++) {
			if (arr[r][cctv.c] == 6) break;
			arr[r][cctv.c] = -1;
		}
	}
	if (dir == 3) {
		for (int c = cctv.c+1; c < m; c++) {
			if (arr[cctv.r][c] == 6) break;
			arr[cctv.r][c] = -1;
		}
	}
}

void map_reset(int after_map[8][8], int before_map[8][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			after_map[i][j] = before_map[i][j];
		}
	}
}

void dfs(int cctv_index) {
	if (cctv_index == cctv_size) {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					temp++;
				}
			}
		}
		if (ret > temp) {
			ret = temp;
		}
		return;
	}
	int backup[8][8];
	int type = cctv[cctv_index].type;
	for (int dir_info = 0; dir_info < cctv_info[type];dir_info++) {
		map_reset(backup, arr);
		if (type == 0) {
			update(dir_info, cctv[cctv_index]);
		}
		if (type == 1) {
			update(dir_info, cctv[cctv_index]);
			update(dir_info + 2, cctv[cctv_index]);
		}
		if (type == 2) {
			update(dir_info, cctv[cctv_index]);
			update(dir_info + 1, cctv[cctv_index]);
		}
		if (type == 3) {
			update(dir_info, cctv[cctv_index]);
			update(dir_info + 1, cctv[cctv_index]);
			update(dir_info + 2, cctv[cctv_index]);
		}
		if (type == 4) {
			update(dir_info, cctv[cctv_index]);
			update(dir_info + 1, cctv[cctv_index]);
			update(dir_info + 2, cctv[cctv_index]);
			update(dir_info + 3, cctv[cctv_index]);
		}
		dfs(cctv_index + 1);
		map_reset(arr, backup);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				cctv[cctv_size].c = j;
				cctv[cctv_size].r = i;
				cctv[cctv_size].type = arr[i][j] - 1;
				cctv_size++;
			}
		}
	}
	ret = 100;
	dfs(0);
	cout << ret;
	return 0;
}