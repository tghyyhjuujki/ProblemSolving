#include <iostream>
#include <vector>
using namespace std;
  
int t, ret, num = 0, n, core, max_core;
int arr[12][12];
bool temp_x;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
vector<pair<int, int> > v;
  
int cnt_line(int cnt) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 2)cnt++;
        }
    }
    return cnt;
}
  
void del(int depth, int d, int cnt, bool x) {
    if (x == true) core--;
    int r = v[depth].first;
    int c = v[depth].second;
    while (cnt--) {
        r = r + dr[d];
        c = c + dc[d];
        if (r < 0 || c < 0 || r >= n || c >= n)return;
        arr[r][c] = 0;
    }
}
  
int update(int depth, int d) {
    int cnt = 0;
    int r = v[depth].first;
    int c = v[depth].second;
    while (1) {
        r = r + dr[d];
        c = c + dc[d];
        if (r < 0 || c < 0 || r >= n || c >= n) {
            core++;
            temp_x = true;
            return cnt;
        }
        else if (arr[r][c] != 0) {
            del(depth, d, cnt, false);
            return 0;
        }
        cnt++;
        arr[r][c] = 2;
    }
}
  
void dfs(int depth) {
    if (depth == v.size()) {
        if (max_core < core) {
            max_core = core;
            int cnt = cnt_line(0);
            ret = cnt;
        }
        else if (max_core == core) {
            int cnt = cnt_line(0);
            if (ret > cnt) ret = cnt;
        }
        return;
    }
    int temp;
    temp_x = false;
    for (int i = 0; i < 4; ++i) {
        temp = update(depth, i);
        if (temp == 0 && temp_x == true)continue;
        dfs(depth + 1);
        if (temp > 0)
            del(depth, i, temp, true);
    }
  
}
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        ret = 0, max_core = 0, core = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
                if (arr[i][j] == 1) {
                    if (i >= 1 && j >= 1 && i < n - 1 && j < n - 1) {
                        v.push_back({ i,j });
                    }       
                }
            }
        }
        dfs(0);
        v.clear();
        num++;
        cout << '#' << num << ' ' << ret << '\n';
    }   
    return 0;
}