#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n;
	int nodeNum, parent, child, node1, node2;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> nodeNum;
		bool check[10001] = { false, };
		vector<int> node(nodeNum + 1);
		for (int j = 0; j < nodeNum - 1; ++j) {
			cin >> parent >> child;
			node[child] = parent;
		}
		cin >> node1 >> node2;
		queue<int> q;
		q.push(node1);
		q.push(node2);
		check[node1] = true;
		check[node2] = true;
		while (true) {
			int nowNode = q.front();
			q.pop();
			if (node[nowNode] == 0) continue;
			if (check[node[nowNode]] == true) {
				cout << node[nowNode] << '\n';
				break;
			}
			check[node[nowNode]] = true;
			q.push(node[nowNode]);
		}
	}	
	return 0;
}