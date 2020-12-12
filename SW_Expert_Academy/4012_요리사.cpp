#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ret, t, num = 0, n, d_n;
int arr[16][16];
vector<int> v[2];
 
void update() {
    int temp[2] = {};
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < d_n; ++i) {
            for (int j = 0; j < d_n; ++j) {
                if (i == j)continue;
                temp[k] += arr[v[k][i]][v[k][j]];
            }
        }
    }
    int tmp = abs(temp[0] - temp[1]);
    if (ret > tmp)ret = tmp;
}
 
void dfs(int depth) {
    if (depth == n) {
        update();
        return;
    }
 
    for (int i = 0; i < 2; ++i) {
        if (v[i].size() == d_n)continue;
        v[i].push_back(depth);
        dfs(depth + 1);
        v[i].pop_back();
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        d_n = n / 2;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> arr[i][j];
 
        ret = 100000;
        v[0].push_back(0);//이게 중요
        dfs(1);
        v[0].clear(); v[1].clear();
        num++;
        cout << '#' << num << ' ' << ret << '\n';
    }
    return 0;
}