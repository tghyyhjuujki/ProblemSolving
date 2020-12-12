#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, target, ret = 0, root;
vector<int> v[50];
bool check[50];
queue<int> q;

int main() {
	cin >> n, target;
	int node;
	for (int i = 0; i < n; ++i) {
		cin >> node;
		if (node != -1) {
			v[i].push_back(node);
			v[node].push_back(i);
		}
		else root = i;
	}
	cin >> target;
	check[target] = true;
	
	if (check[root] == false) {
		check[root] = true;
		q.push(root);
		while (!q.empty()) {
			int nnode = q.front();
			int v_size = v[nnode].size();
			bool state = false;
			q.pop();
			for (int i = 0; i < v_size; ++i) {
				if (check[v[nnode][i]] == true) continue;
				state = true;
				check[v[nnode][i]] = true;
				q.push(v[nnode][i]);
			}
			if (state == false)ret++;
		}
	}
	cout << ret;
	return 0;
}