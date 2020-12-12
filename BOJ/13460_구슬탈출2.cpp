#include <iostream>
#include <string>
using namespace std;

int n, m, ret = 20, rr, rc, br, bc;
bool goalR = false, goalB = false;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
string str[10];

void copy(string str1[10], string str2[10]) {
	for (int i = 0; i < n; ++i) {
		str1[i] = str2[i];
	}
}

void moveR(int r, int c, int d) {
	int nrr = r + dr[d];
	int nrc = c + dc[d];
	if (str[nrr][nrc] == '.') moveR(nrr, nrc, d);
	else if (str[nrr][nrc] == 'O') {
		goalR = true;
		str[rr][rc] = '.';
		rr = r; rc = c;
	}
	else {
		str[rr][rc] = '.';
		rr = r; rc = c;
		str[r][c] = 'R';
	}
}

void moveB(int r, int c, int d) {
	int nbr = r + dr[d];
	int nbc = c + dc[d];
	if (str[nbr][nbc] == '.') moveB(nbr, nbc, d);
	else if (str[nbr][nbc] == 'O') {
		goalB = true;
		str[br][bc] = '.';
		br = r; bc = c;
	}
	else {
		str[br][bc] = '.';
		br = r; bc = c;
		str[r][c] = 'B';
	}
}

void dfs(int depth) {
	if (depth > 10) return;
	if (goalR == true) {
		if (goalB == false) {
			if (ret > depth) ret = depth;
			return;
		}
		else return;
	}
	else {
		if (goalB == true) return;
	}

	string backup[10];
	int temprr, temprc, tempbr, tempbc;
	bool gr, gb;
	for (int i = 0; i < 4; ++i) {
		copy(backup, str);
		temprr = rr; temprc = rc; tempbr = br; tempbc = bc;
		gr = goalR; gb = goalB;
		if (str[rr + dr[i]][rc + dc[i]] != '.' && str[rr + dr[i]][rc + dc[i]] != 'O') {
			if (str[br + dr[i]][bc + dc[i]] != '.' && str[br + dr[i]][bc + dc[i]] != 'O') continue;
			moveB(br, bc, i);
			moveR(rr, rc, i);
			moveB(br, bc, i);
		}
		else {
			moveR(rr, rc, i);
			moveB(br, bc, i);
			moveR(rr, rc, i);
		}
		dfs(depth + 1);
		goalR = gr; goalB = gb;
		rr = temprr; rc = temprc; br = tempbr; bc = tempbc;
		copy(str, backup);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> str[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (str[i][j] == 'R') {
				rr = i; rc = j;
			}
			if (str[i][j] == 'B') {
				br = i; bc = j;
			}
		}
	}
	dfs(0);
	if (ret == 20) ret = -1;
	cout << ret;
	return 0;
}