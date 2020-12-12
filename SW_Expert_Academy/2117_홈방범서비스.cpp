#include <iostream>
#include <queue>
using namespace std;
int t, n, m, num = 0, ret, max_value, end_value;
int arr[20][20];
int temp_base[21];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
queue<pair<int, int> > q;
 
void update(int r, int c, int value) {
    int x = 0, home_cnt = 0;
    int check[20][20] = {0};
    check[r][c] = 1;
    if (arr[r][c] == 1) x += m;
 
    q.push({ r,c });
    int cnt = 1;
    while (!q.empty()) {
        int q_size = q.size();
 
        cnt++;
        while (q_size--) {
 
            r = q.front().first;
            c = q.front().second;
            q.pop();
 
            for (int i = 0; i < 4; i++) {
 
                int nr = r + dy[i];
                int nc = c + dx[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || check[nr][nc] != 0)continue;
                if (check[nr][nc] == 0) {
                    check[nr][nc] = cnt;
                    q.push({ nr,nc });
                    if (check[nr][nc] == value) return;
                    if (arr[nr][nc] == 1) {
                        x += m;
                    }
                }
            }
        }
 
        if (temp_base[cnt] <= x) {
            home_cnt = x / m;
        }
 
        if (ret < home_cnt) ret = home_cnt;
    }
}
 
void make_base() {
    for (int i = 1; i < 21; i++) {
        temp_base[i] = i * i + (i - 1)*(i - 1);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    make_base();
 
    cin >> t;
    while (t--) {
        end_value = 0; ret = 0; max_value = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 1) {
                    max_value++;
                }
            }
        }
 
        for (int i = 1; i < 21; i++) {
            if (temp_base[i] > max_value * m) {
                end_value = i;
                break;
            }
        }
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                update(i, j, end_value);
                while (!q.empty()) {q.pop();}
            }
        }
        if (ret == 0) ret = 1;
        num++;
        cout << '#' << num << ' ' << ret << "\n";
    }
    return 0;
}