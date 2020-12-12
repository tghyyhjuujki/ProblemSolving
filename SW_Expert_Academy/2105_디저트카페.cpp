#include <iostream>
#include <cstring>
using namespace std;
 
int t, n, ret, r, c, num = 0;
int arr[20][20];
int dr[4] = { 1,1,-1,-1 };
int dc[4] = { 1,-1,-1,1 };
bool taste[101] = {};
 
void dfs(int depth, int sr, int sc, int dir) {
     
    if (depth > 0 && r == sr && c == sc) {
        if (ret < depth)ret = depth;
        return;
    }
 
    taste[arr[sr][sc]] = 1;
    int nr, nc;
    for (int i = 0; i < 2; ++i) {
        nr = sr + dr[(dir + i) % 4];
        nc = sc + dc[(dir + i) % 4];
        if (nr < r || nc < 0 || nr >= n || nc >= n) continue;
        if (taste[arr[nr][nc]] == 1 && (r != nr || c != nc)) continue;
        dfs(depth + 1, nr, nc, (dir + i) % 4);
        if (nr == r && nc == c) continue;
        taste[arr[nr][nc]] = 0;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }
        ret = 0;
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                r = i; c = j;
                dfs(0, i, j, 0);
                memset(taste, 0, sizeof(taste));
            }
        }
        memset(arr, 0, sizeof(arr));
        num++;
        if (ret == 0) ret = -1;
        cout << '#' << num << ' ' << ret << '\n';
    }   
    return 0;
}