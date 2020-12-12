#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int t, ret, n;
int arr[10][10], peo_idx[10];
vector<pair<int, int> > peo;
vector<pair<int,int> > s;
vector<int> s1;
vector<int> s2;
queue<int> s1_enter;
queue<int> s2_enter;
//pair로 만들어서 두번째 인자로 경과시간 넣는다
queue<pair<int, int> > s1_ing;
queue<pair<int, int> > s2_ing;
 
int update() {
    int temp, x;
    for (int i = 0; i < peo.size(); ++i) {
        //첫번째 계단
        if (peo_idx[i] == 1) {
            x = abs(s[0].first - peo[i].first) + abs(s[0].second - peo[i].second);
            s1.push_back(x);
        }
        //두번째 계단
        else {
            x = abs(s[1].first - peo[i].first) + abs(s[1].second - peo[i].second);
            s2.push_back(x);
        }
    }
    sort(s1.begin(), s1.end(), greater<int>());
    sort(s2.begin(), s2.end(), greater<int>());
 
    int temp_t = 0, t1, t2;
    while (1) {
        temp_t++;
        //첫번쨰 계단
        //계단ing 진행
        int size1i = s1_ing.size();
        for (int i = 0; i < size1i; ++i) {
            if (temp_t - s1_ing.front().second == arr[s[0].first][s[0].second]) {
                s1_ing.pop();
            }
            else break;
        }
        //ing 3 미만이면 대기줄에서 빼기 + 1초이상 대기했는지
        int size1e = s1_enter.size();
        for (int i = 0; i < size1e; ++i) {
            if (s1_ing.size() < 3) {
                s1_ing.push({ s1_enter.front(), temp_t});
                s1_enter.pop();
            }
            else break;
        }
        //사람들 대기줄에 넣기
        int size1 = s1.size();
        for (int i = 0; i < size1; ++i) {
            if (s1.back() <= temp_t) {
                s1_enter.push(s1.back());
                s1.pop_back();
            }
            else break;
        }
        //두번쨰 계단
        int size2i = s2_ing.size();
        for (int i = 0; i < size2i; ++i) {
            if (temp_t - s2_ing.front().second == arr[s[1].first][s[1].second]) {
                s2_ing.pop();
            }
            else break;
        }
        int size2e = s2_enter.size();
        for (int i = 0; i < size2e; ++i) {
            if (s2_ing.size() < 3) {
                s2_ing.push({ s2_enter.front(), temp_t });
                s2_enter.pop();
            }
            else break;
        }
        int size2 = s2.size();
        for (int i = 0; i < size2; ++i) {
            if (s2.back() <= temp_t) {
                s2_enter.push(s2.back());
                s2.pop_back();
            }
            else break;
        }
 
        if (s1.size() == 0 && s1_enter.size() == 0 && s1_ing.size() == 0 &&
            s2.size() == 0 && s2_enter.size() == 0 && s2_ing.size() == 0) return temp_t;
    }
}
 
void dfs(int depth) {
    if (depth == peo.size()) {
        int temp = update();
        if (ret > temp)ret = temp;
        return;
    }
 
    //사람 분배
    for (int i = 1; i <= 2; ++i) {
        if (peo_idx[depth] != 0)continue;
        peo_idx[depth] = i;
        dfs(depth + 1);
        peo_idx[depth] = 0;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    int num = 0;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
                if (arr[i][j] == 1)peo.push_back({ i,j });
                else if (arr[i][j] > 1)s.push_back({ i,j });
            }
        }
        ret = 100000;
        dfs(0);
        peo.clear();
        s.clear();
        num++;
        cout << '#' << num << ' ' << ret << "\n";
    }
    return 0;
}