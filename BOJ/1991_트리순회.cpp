#include <iostream>
using namespace std;
struct Tree {
	char data;
	Tree* left;
	Tree* right;
	Tree() {
		data = NULL;
		left = NULL;
		right = NULL;
	}
};

void preorder(Tree* node) {
	if (node->data == '.')return;
	cout << node->data;
	if (node->left != NULL) preorder(node->left);
	if (node->right != NULL) preorder(node->right);
}

void inorder(Tree* node) {
	if (node->data == '.')return;
	if (node->left != NULL) inorder(node->left);
	cout << node->data;
	if (node->right != NULL) inorder(node->right);
}

void postorder(Tree* node) {
	if (node->data == '.')return;
	if (node->left != NULL) postorder(node->left);
	if (node->right != NULL) postorder(node->right);
	cout << node->data;
}


int main() {
	cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);
	int nodeNumber;
	char data, left, right;
	cin >> nodeNumber;
	Tree *tree = new Tree[nodeNumber];
	for (int i = 0; i < nodeNumber; ++i) {	
		cin >> data >> left >> right;
		tree[(int)data - 65].data = data;
		if (left != '.')
			tree[(int)data - 65].left = &tree[(int)left - 65];
		if (right != '.')
			tree[(int)data - 65].right = &tree[(int)right - 65];
	}
	preorder(tree);
	cout << '\n';
	inorder(tree);
	cout << '\n';
	postorder(tree);
	return 0;
}