#include <iostream>
#include <queue>
using namespace std;
int t, ret, n, w, h;
int arr[15][12];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
queue<pair<int, int> > q;
 
void map_copy(int arr1[15][12], int arr2[15][12]) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            arr1[i][j] = arr2[i][j];
        }
    }
}
 
void update(int x) {
    for (int i = 0; i < h; ++i) {
        if (arr[i][x] > 1) {
            q.push({ i,x });
            break;
        }
        else if (arr[i][x] == 1) {
            arr[i][x] = 0;
            break;
        }
    }
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        int temp = arr[r][c];
        arr[r][c] = 0;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r, nc = c;
            for (int j = 1; j < temp; ++j) {
                nr += dr[i];
                nc += dc[i];
                if (nr < 0 || nc < 0 || nr >= h || nc >= w)continue;
                if (arr[nr][nc] == 1) arr[nr][nc] = 0;
                else if (arr[nr][nc] > 1) q.push({ nr,nc });
            }
        }
    }
 
    //중력
    for (int i = h - 2; i >= 0; --i) {
        for (int j = 0; j < w; ++j) {
            if (arr[i][j] > 0 && arr[i + 1][j] == 0) {
                int temp = i + 1;
                while (1) {
                    if (temp == h || arr[temp][j] != 0) {
                        arr[temp - 1][j] = arr[i][j];
                        arr[i][j] = 0;
                        break;
                    }
                    else if (arr[temp][j] == 0) {
                        temp++;
                        continue;
                    }
                }
            }
        }
    }
}
 
void dfs(int depth) {
    if (depth == n) {
        int temp = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (arr[i][j] > 0) temp++;
            }
        }
        if (ret > temp)ret = temp;
        return;
    }
 
    int arr_temp[15][12];
    for (int i = 0; i < w; ++i) {
        map_copy(arr_temp, arr);
        update(i);
        dfs(depth + 1);
        map_copy(arr, arr_temp);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    int num = 0;
    while (t--) {
        cin >> n >> w >> h;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> arr[i][j];
            }
        }
        ret = 10000;
        dfs(0);
        num++;
        cout << '#' << num << ' ' << ret << "\n";
    }
    return 0;
}