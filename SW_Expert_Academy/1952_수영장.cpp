#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int t, num = 0, ret;
int arr[12], p[4];
 
void dfs(int arr_idx, int sum) {
 
    if (arr_idx >= 12) {
        if (ret > sum)ret = sum;
        return;
    }
     
    if (arr[arr_idx] == 0) {
        dfs(arr_idx + 1, sum);
        return;
    }
 
    for (int i = 0; i < 4; ++i) {
        if (i == 0) {
            dfs(arr_idx + 1, sum + arr[arr_idx] * p[0]);
        }
        if (i == 1) {
            dfs(arr_idx + 1, sum + p[1]);
        }
        if (i == 2) {
            dfs(arr_idx + 3, sum + p[2]);
        }
        if (i == 3) {
            dfs(arr_idx + 12, sum + p[3]);
        }
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        ret = 100000;
        cin >> p[0] >> p[1] >> p[2] >> p[3];
        for (int i = 0; i < 12; ++i) {
            cin >> arr[i];
        }
        dfs(0, 0);
        num++;
        cout << '#' << num << ' ' << ret << '\n';
    }
    return 0;
}