//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

struct Tree {
	int data;
	Tree* left;
	Tree* right;
	Tree(int& data) { this->data = data; left = NULL; right = NULL; }
	void setLeft(Tree* left) { this->left = left; }
	void setRight(Tree* right) { this->right = right; }
};

Tree* insert(Tree* parent, Tree* child) {
	// 집어 넣기 위한 리턴
	if (parent == NULL)return child;
	// 왼쪽일 때
	if (child->data < parent->data)
		parent->setLeft(insert(parent->left, child));
	//오른쪽일 때
	else if (child->data > parent->data)
		parent->setRight(insert(parent->right, child));
	//최종 결과를 Tree* 에 반영
	return parent;
}

void postorder(Tree* root) {
	if (root == NULL)return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int nodeData;
	Tree* tree = NULL;
	while (cin >> nodeData)
		tree = insert(tree, new Tree(nodeData));

	postorder(tree);
	return 0;
}