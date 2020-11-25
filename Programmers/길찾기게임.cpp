//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct TREE {
	int idx, x, y;
	// 자식노드를 지시하기 위한 포인터
	TREE* left;
	TREE* right;
};

// y가 클수록 root, 왼쪽부터 넣을 시 노드의 레벨이 같을 때 x가 작아야 하므로 비교함수 작성
bool cmp(TREE a, TREE b) {
	if (a.y == b.y)return a.x < b.x;
	return a.y > b.y;
}

//부모노드와 자식노드를 연결하는 함수, 구조체 포인터를 매개변수로 받아 depth가 깊어질 때
//주소값으로 재귀 가능하게 만듦. left, right 둘다 NULL이면 리프노드이므로, 
//이 문제에는 필요없지만 기억해 놓으면 좋을듯.
void insert(TREE* parent, TREE* child) {
	//자식이 왼쪽
	if (parent->x > child->x) {
		if (parent->left == NULL) {
			parent->left = child;
		}
		else {
			insert(parent->left, child);
		}
	}
	//자식이 오른쪽
	else {
		if (parent->right == NULL) {
			parent->right = child;
		}
		else {
			insert(parent->right, child);
		}
	}
}
// 전위, 출력 또는 push하는 코드를 놓는 위치에 따라 전, 중, 후로 나뉨
void pre(TREE* root, vector<int> &pre_v) {
	if (!root) return;
	pre_v.push_back(root->idx);
	pre(root->left, pre_v);
	pre(root->right, pre_v);
}
// 후위
void post(TREE* root, vector<int> &post_v) {
	if (!root) return;
	post(root->left, post_v);
	post(root->right, post_v);
	post_v.push_back(root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	int size1 = nodeinfo.size();
	vector<TREE> tree;
	for (int i = 0; i < size1; ++i)
		tree.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
	// cmp 함수 기준으로 정렬
	sort(tree.begin(), tree.end(), cmp);

	// 부모와 자식 연결
	for (int i = 1; i < size1; ++i)
		insert(&tree[0], &tree[i]);

	vector<int> pre_v, post_v;
	pre(&tree[0], pre_v);
	post(&tree[0], post_v);
	answer.push_back(pre_v);
	answer.push_back(post_v);
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//[[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]
	//[[7,4,6,9,1,8,5,2,3],[9,6,5,8,1,4,3,2,7]]
	vector<vector<int> > vv;
	vv.push_back({ 5,3 });
	vv.push_back({ 11,5 });
	vv.push_back({ 13,3 });
	vv.push_back({ 3,5 });
	vv.push_back({ 6,1 });
	vv.push_back({ 1,3 });
	vv.push_back({ 8,6 });
	vv.push_back({ 7,2 });
	vv.push_back({ 2,2 });
	solution(vv);
	return 0;
}