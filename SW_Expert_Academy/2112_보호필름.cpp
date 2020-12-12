#include <iostream>
using namespace std;
int ret, t, num, d, w, k, max_val;
int arr[13][20], aob[13];
 
void cp(int arr1[20], int arr2[20]) {
    for (int i = 0; i < w; ++i)
        arr1[i] = arr2[i];
}
 
bool update() {
    for (int j = 0; j < w; ++j) {
        int a = arr[0][j];
        int i = 0, cnt = 1, x = d - 1;
        while (x--) {
            if (cnt == k) break;
            i++;
            if (arr[i][j] == a) {
                cnt++;
                continue;
            }
            else {
                a = arr[i][j];
                cnt = 1;
                continue;
            }
        }
        if (cnt < k)return false;
    }
    return true;
}
 
void dfs(int depth, int x) {
    if (depth == max_val) {
        if (update() == true && ret > depth) ret = depth;
        return;
    }
    int arr_temp[20];
    for (int i = x; i < d; ++i) {
        cp(arr_temp, arr[i]);
        aob[depth] = i;
        for (int j = 0; j < 2; ++j) {
            for (int l = 0; l < w; ++l)
                arr[i][l] = j;
            dfs(depth + 1, i + 1);
        }
        aob[depth] = 0;
        cp(arr[i], arr_temp);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> d >> w >> k;
        for (int i = 0; i < d; ++i)
            for (int j = 0; j < w; ++j)
                cin >> arr[i][j];
        ret = 10000;
        for (int i = 0; i < k; ++i) {
            max_val = i;
            dfs(0, 0);
        }
        num++;
        if (ret == 10000)ret = k;
        cout << '#' << num << ' ' << ret << '\n';
    }
    return 0;
}