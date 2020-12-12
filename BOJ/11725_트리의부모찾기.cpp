//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void checkParent(vector<vector<int> >& nodeList, vector<int>& checkParentNode) {
	// 첫번째 노드번호, 두번째 자식
	queue<pair<int, int> > q;

	// 1번 노드의 자식들 큐에 삽입
	for (int i = 0; i < nodeList[1].size(); ++i)
		q.push({ 1, nodeList[1][i] });

	while (q.size()) {
		int parent = q.front().first;
		int child = q.front().second;
		q.pop();

		for (int i = 0; i < nodeList[child].size(); ++i) {
			if (checkParentNode[nodeList[child][i]] != 0)
				checkParentNode[child] = nodeList[child][i];
			else q.push({ child, nodeList[child][i] });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int nodeNumber, firstNode, secondNode;
	cin >> nodeNumber;
	vector<vector<int> > nodeList(nodeNumber + 1, vector<int>(NULL));
	vector<int> checkParentNode(nodeNumber + 1);
	checkParentNode[1] = -1;
	for (int i = 0; i < nodeNumber - 1; ++i) {
		cin >> firstNode >> secondNode;
		nodeList[firstNode].push_back(secondNode);
		nodeList[secondNode].push_back(firstNode);
	}
	checkParent(nodeList, checkParentNode);

	for (int i = 2; i <= nodeNumber; ++i)
		cout << checkParentNode[i] << '\n';
	return 0;
}