//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int ver, e, u, v, w, start;
const int MAX = 20001;
const int INF = 0x12341234;

struct VERCO {
	int cost, vertex;
}verco;
bool operator< (VERCO a, VERCO b) {
	return a.cost > b.cost;
}

vector<VERCO> arr[MAX];
priority_queue<VERCO> pq;

vector<int> update(int ver, int start) {
	vector<int> dis(ver + 1, INF);
	dis[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int nowcost = pq.top().cost;
		int nowver = pq.top().vertex;
		pq.pop();
		if (dis[nowver] > nowcost) continue;

		for (int i = 0; i < arr[nowver].size(); ++i) {
			int nextver = arr[nowver][i].vertex;
			int nextcost = arr[nowver][i].cost + nowcost;
			if (dis[nextver] > nextcost) {
				dis[nextver] = nextcost;
				pq.push({ nextcost,nextver });
			}
		}
	}
	return dis;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> ver >> e >> start;
	for (int i = 0; i < e; ++i) {
		cin >> u >> v >> w;
		arr[u].push_back({ w, v });
	}
	vector<int> result = update(ver, start);

	for (int i = 1; i <= ver; i++){
		if (result[i] == INF)
			cout << "INF\n";
		else
			cout << result[i] << "\n";
	}
	return 0;
}