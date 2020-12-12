#include <iostream>
#include <queue>
using namespace std;
 
struct SEMI {
    int r, c, cnt, dir;
}semi;
 
struct MAP {
    int cnt, max, dir;
};
 
int t, n, m_time, k_cnt;
int r, c, cnt, dir;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
MAP map[100][100];
 
int bfs(queue<SEMI> q, int ret) {
    int time_cnt = 0;
 
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int r = q.front().r;
            int c = q.front().c;
            int cnt = q.front().cnt;
            int dir = q.front().dir;
            q.pop();
 
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n)continue;
            if (nr == 0 || nc == 0 || nr == n - 1 || nc == n - 1) {
                if (dir % 2 == 0) dir += 1;
                else if (dir % 2 == 1) dir -= 1;
                cnt = cnt / 2;
            }
            //맵에 이미 있을 때
            if (map[nr][nc].cnt > 0) {
                if (map[nr][nc].max < cnt) {
                    map[nr][nc].max = cnt;
                    map[nr][nc].dir = dir;
                }
                map[nr][nc].cnt += cnt;
            }
            //없을 때
            else {
                map[nr][nc].cnt = map[nr][nc].max = cnt;
                map[nr][nc].dir = dir;
            }
        }
        time_cnt++;
        if (time_cnt == m_time) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (map[i][j].cnt > 0) {
                        ret += map[i][j].cnt;
                        map[i][j].cnt = map[i][j].dir = map[i][j].max = 0;
                    }
                }
            }
            return ret;
        }
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (map[i][j].cnt > 0)
                    q.push({ i,j,map[i][j].cnt,map[i][j].dir });
                map[i][j].cnt = map[i][j].dir = map[i][j].max = 0;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    int asdf = 0;
    while (t--) {
        queue<SEMI> q;
        cin >> n >> m_time >> k_cnt;
        for (int i = 0; i < k_cnt; ++i) {
            cin >> r >> c >> cnt >> dir;
            q.push({ r,c,cnt,dir - 1});
        }
        int ret = 0;
        asdf++;
        cout << '#' << asdf << ' ' << bfs(q, ret) << '\n';
    }   
    return 0;
}