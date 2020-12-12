#include <iostream>
#include <vector>
using namespace std;
int t, num = 0, ret, n;
int check[4001][4001];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
struct ATOM {
    int r, c, d, k;
    bool state;
}atom;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        ATOM v[1001];
        for (int i = 1; i <= n; ++i) {
            cin >> atom.c >> atom.r >> v[i].d >> v[i].k;
            v[i].r = (1000 - atom.r) * 2;
            v[i].c = (atom.c + 1000) * 2;
            v[i].state = false;
        }
        ret = 0;
        while (1) {
            bool temp = false;
            for (int i = 1; i <= n; ++i) {
                bool state = v[i].state;
                if (state == 1)continue;
                int r = v[i].r, c = v[i].c;
                int d = v[i].d, k = v[i].k;
                temp = true;
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nc < 0 || nr>4000 || nc>4000) {
                    v[i].state = true;
                    continue;
                }
                if (check[nr][nc] == 0) {
                    check[nr][nc] = i;
                    v[i].r = nr; v[i].c = nc;
                }
                else if(check[nr][nc] == -1){
                    ret += v[i].k;
                    v[i].state = true;
                }
                //conflict
                else {
                    v[check[nr][nc]].state = true; v[i].state = true;
                    ret += v[check[nr][nc]].k + v[i].k;
                    check[nr][nc] = -1;
                }
            }
            if (temp == false)break;
            for (int i = 1; i <= n; ++i) check[v[i].r][v[i].c] = 0;
        }
        num++;
        cout << '#' << num << ' ' << ret << '\n';
    }
    return 0;
}