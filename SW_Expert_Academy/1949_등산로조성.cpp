#include<iostream>
#include<vector>
using namespace std;
int t, n, k, max_temp, num = 0;
int arr[8][8];
int check[8][8];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
bool k_able = true;
 
vector<pair<int, int> > v;
 
void dfs(int r, int c, int d){
    check[r][c] = 1;
 
    for (int i = 0; i < 4; i++) {
        int nr = r + dy[i];
        int nc = c + dx[i];
        if (0 <= nr && nr < n && 0 <= nc && nc<n && arr[r][c]>arr[nr][nc] && check[nr][nc] == 0) {
            check[nr][nc] = 1;
            dfs(nr, nc, d + 1);
            check[nr][nc] = 0;
        }
        else {
            if (max_temp < d) {
                max_temp = d;
            }
            continue;
        }
         
 
    }
}
int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        v.clear();
        int max_val = 0; max_temp = 0;
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                cin >> arr[j][l];
                if (arr[j][l] > max_val) {
                    max_val = arr[j][l];
                }
            }
        }
         
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                if (arr[j][l] == max_val) {
                    v.push_back(make_pair(j, l));
                }
            }
        }
 
        for (int x = 1; x <= k; x++) {
            for (int y = 0; y < n; y++) {
                for (int z = 0; z < n; z++) {
                    if (y == 2 && z == 3) {
                        y = 2; z = 3;
                    }
                    arr[y][z] -= x;
                    for (int j = 0; j < v.size(); j++) {
                        dfs(v[j].first, v[j].second, 1);
                        for (int o = 0; o < n; o++) {
                            for (int p = 0; p < n; p++) {
                                check[o][p] = 0;
                            }
                        }
                    }
                    arr[y][z] += x;
                }
            }
        }
         
        num++;
        cout << '#' << num << ' ' << max_temp << "\n";
    }
    return 0;
}