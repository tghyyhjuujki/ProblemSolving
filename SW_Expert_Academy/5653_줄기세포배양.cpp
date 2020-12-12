#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int t, ret, n, m, k;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
 
//state -1사망 0 비활성 1 활성
struct J_MAP {
    int life, state, cnt, temp_t;
}j_map;
J_MAP arr[360][360];
 
struct Q {
    int r, c, life;
}QQ;
queue<Q> q;
 
void bfs() {
    int temp_time = 0;
    while (1) {
        temp_time++;
        if (temp_time == k + 1) {
            ret = q.size();
            while (!q.empty())q.pop();
            break;
        }
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int r = q.front().r;
            int c = q.front().c;
            int state = arr[r][c].state;
            int life = arr[r][c].life;
            q.pop();
            arr[r][c].cnt++;
            arr[r][c].temp_t = temp_time;
 
            if (state == 1 && arr[r][c].cnt == 1) {
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (arr[nr][nc].life >= arr[r][c].life || arr[nr][nc].state != 0 || arr[nr][nc].cnt > 0) continue;
                    if (arr[nr][nc].temp_t != 0 && arr[nr][nc].temp_t != arr[r][c].temp_t)continue;
                    arr[nr][nc].life = arr[r][c].life;
                    arr[nr][nc].temp_t = temp_time;
                    q.push({ nr,nc, arr[nr][nc].life});
                }
            }
 
            if (arr[r][c].cnt == life) {
                if (state == 0) {
                    arr[r][c].state = 1;
                    arr[r][c].cnt = 0;
                }
                else if (state == 1) {
                    arr[r][c].state = -1;
                    continue;
                }
            }
             
            q.push({ r,c,arr[r][c].life });
        }
        //q에 들어간놈의 라이프가 맵의 라이프랑 다르면 버림
        int size_q = q.size();
        for (int i = 0; i < size_q; ++i) {
            int r = q.front().r;
            int c = q.front().c;
            int life = q.front().life;
            if (life == arr[q.front().r][q.front().c].life) q.push({ r,c,life });
            q.pop();
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    int num = 0;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i + 151][j + 151].life;
                if (arr[i + 151][j + 151].life > 0) q.push({ i + 151,j + 151 });
            }
        }
        bfs();
        memset(arr, 0, sizeof(arr));
        num++;
        cout << '#' << num << ' ' << ret << "\n";
    }
    return 0;
}