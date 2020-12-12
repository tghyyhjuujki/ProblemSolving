#include <iostream>
#include <queue>
using namespace std;
//n = 접수창구개수, m = 정비개수, k = 손님수, a = 접수시간, b = 정비시간
int t, num = 0, ret, n, m, k, a, b;
int an_time[9], bm_time[9];
//an, 접수창구 이용중인 손님의 번호, 경과시간
pair<int, int> an[9];
//an, bm, 접수창구 이용중인 손님의 번호, 접수창구 번호, 경과시간
pair<pair<int, int>, int> bm[9];
//q 몇번째 손님, 각 도착시간
queue<pair<int, int> > q;
 
struct QQ {
    int n_k, n_an;
}qq;
 
bool operator<(QQ a, QQ b) {
    return a.n_an > b.n_an;
}
 
//q2, 몇번째 손님, 이용접수창구 번호, 총 경과시간
priority_queue<QQ> q2;
//q3, 몇번째손님, 이용접수창구번호
queue<pair<int, int> > q3;
 
void update(int t, int max_time) {
    t--;
    while (1) {
        t++;
        bool check_an = false, check_bm = false;
         
        //접수창구 시간소요
        for (int i = 0; i < n; ++i) {
            if (an[i].first != 0) {
                check_an = true;
                an[i].second++;
                if (an[i].second == an_time[i]) {
                    qq.n_k = an[i].first; qq.n_an = i;
                    q2.push(qq);
                    an[i].first = 0; an[i].second = 0;
                }
            }
        }
        //정비창구 시간소요
        for (int i = 0; i < m; ++i) {
            if (bm[i].first.first != 0) {
                check_bm = true;
                bm[i].second++;
                if (bm[i].second == bm_time[i]) {
                    if (bm[i].first.second == a && i == b) {
                        ret += bm[i].first.first;
                    }
                    bm[i].first.first = 0; bm[i].first.second = 0;
                    bm[i].second = 0;
                }
            }
        }
        //접수창구 집어넣기
        for (int i = 0; i < n; ++i) {
            if (an[i].first == 0) {
                if (!q.empty() && q.front().second <= t) {
                    check_an = true;
                    an[i].first = q.front().first;
                    q.pop();
                }
            }
        }
        //정비창구 대기줄 생성
        while(!q2.empty()) {
            q3.push({ q2.top().n_k, q2.top().n_an });
            q2.pop();
        }
        //정비창구 집어넣기
        for (int i = 0; i < m; ++i) {
            if (bm[i].first.first == 0) {
                if (!q3.empty()) {
                    check_an = true;
                    bm[i].first.first = q3.front().first;
                    bm[i].first.second = q3.front().second;
                    q3.pop();
                }
            }
        }
        if (check_bm == 0 && check_an == 0 && q.empty() && q3.empty() && t>= max_time) break;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> a >> b;
        a--; b--;
        int arr_time, max_time;
        for (int i = 0; i < n; ++i) {
            cin >> an_time[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> bm_time[i];
        }
        for (int i = 0; i < k; ++i) {
            cin >> arr_time;
            q.push({ i + 1, arr_time });
            if (i == k - 1) max_time = arr_time;
        }
        ret = 0;
        update(q.front().second, max_time);
        num++;
        if (ret == 0) ret = -1;
        cout << '#' << num << ' ' << ret << '\n';
    }
    return 0;
}