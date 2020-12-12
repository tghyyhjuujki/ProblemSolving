#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int t, num = 0, ret, n, m, max_val, ret_temp[2];
int arr[10][10];
bool check[10][10] = {};
vector<int> v[2];
vector<int> v_temp;
 
void update(int x, int idx, int now_c) {
 
    for (int i = x; i < v[idx].size(); ++i) {
        if (now_c >= v[idx][i]) {
            v_temp.push_back(v[idx][i]);
            now_c -= v[idx][i];
            int temp = 0;
            for (int j = 0; j < v_temp.size(); j++) {
                temp += v_temp[j] * v_temp[j];
            }
            if (ret_temp[idx] < temp) ret_temp[idx] = temp;
        }
        else return;
        update(i + 1, idx, now_c);
        now_c += v[idx][i];
        v_temp.pop_back();
    }
}
 
void dfs(int depth, int r, int c) {
    if (depth == 2) {
        ret_temp[0] = 0;
        update(0, 0, max_val);
        ret_temp[1] = 0;
        update(0, 1, max_val);
        int temp = ret_temp[0] + ret_temp[1];
        if (ret < temp) ret = temp;
        return;
    }
    if (c >= n) {
        if (r + 1 == n) return;
        dfs(depth, r + 1, 0);
    }
    for (int i = r; i < n; ++i) {
         
        for (int j = c; j < n; ++j) {
            if (check[i][j] == 1)continue;
 
            if (j + m > n) {
                if (r + 1 == n) return;
                dfs(depth, r + 1, 0);
                return;
            }
 
            for (int k = 0; k < m; ++k) {
                v[depth].push_back(arr[i][j + k]);
                check[i][j + k] = 1;
            }
            dfs(depth + 1, i, j + m);
            for (int k = 0; k < m; ++k) {
                check[i][j + k] = 0;
            }
            v[depth].clear();
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m >> max_val;
        ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }
        dfs(0, 0, 0);
        num++;
        cout << '#' << num << ' ' << ret << '\n';
    }
    return 0;
}