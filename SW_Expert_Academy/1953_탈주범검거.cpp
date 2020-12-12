#include <iostream>
#include <queue>
using namespace std;
 
int t, ret, num = 0,N,M,R,C,L;
int arr[50][50];
 
queue<pair<int, int> > q;
 
void bfs() {
    int check[50][50] = {};
    check[R][C] = 1;
    while (L--) {
        int size = q.size();
        while (size--) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int a = arr[r][c];
            for (int i = 0; i < 4; ++i) {
                if (i == 0 && (a == 1 || a == 2 || a == 4 || a == 7)) {
                    if (r - 1 < 0)continue;
                    int na = arr[r - 1][c];
                    if (na == 0 || na == 3 || na == 4 || na == 7 || check[r-1][c] != 0)continue;
                    check[r - 1][c] = check[r][c] + 1;
                    q.push({ r - 1,c });
                }
                else if (i == 1 && (a == 1 || a == 2 || a == 5 || a == 6)) {
                    if (r + 1 >= N)continue;
                    int na = arr[r + 1][c];
                    if (na == 0 || na == 3 || na == 5 || na == 6 || check[r+1][c] != 0)continue;
                    check[r + 1][c] = check[r][c] + 1;
                    q.push({ r + 1,c });
                }
                else if (i == 2 && (a == 1 || a == 3 || a == 6 || a == 7)) {
                    if (c - 1 < 0)continue;
                    int na = arr[r][c - 1];
                    if (na == 0 || na == 2 || na == 6 || na == 7 || check[r][c-1] != 0)continue;
                    check[r][c - 1] = check[r][c] + 1;
                    q.push({ r,c - 1 });
                }
                else if (i == 3 && (a == 1 || a == 3 || a == 4 || a == 5)) {
                    if (c + 1 >= M)continue;
                    int na = arr[r][c + 1];
                    if (na == 0 || na == 2 || na == 4 || na == 5 || check[r][c+1] != 0)continue;
                    check[r][c + 1] = check[r][c] + 1;
                    q.push({ r,c + 1 });
                }
            }
        }
    }
    ret = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (check[i][j] > 0) ret++;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> N >> M >> R >> C >> L;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> arr[i][j];
            }
        }
        L--;
        q.push({ R,C });
        bfs();
        while (!q.empty())q.pop();
        num++;
        cout << '#' << num << ' ' << ret << '\n';
    }   
    return 0;
}