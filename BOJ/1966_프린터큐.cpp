//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m, cnt = 0;
		queue<pair<int, int> > q;
		priority_queue<int> pq;
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			q.push({ j,a });
			pq.push(a);
		}
		while (!q.empty()) {
			int nowidx = q.front().first;
			int nowval = q.front().second;
			q.pop();
			if (pq.top() == nowval) {
				pq.pop();
				cnt++;
				if (nowidx == m) {
					cout << cnt << "\n";
					break;
				}
			}
			else q.push({ nowidx,nowval });
		}
	}
	return 0;
}