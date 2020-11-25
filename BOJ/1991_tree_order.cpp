#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n;
char node, r, l;
int arr[26][2] = { '.', };

void jeon(char root) {
	if (root == '.')return;
	cout << root;
	jeon(arr[root - 'A'][0]);
	jeon(arr[root - 'A'][1]);
}
void joong(char root) {
	if (root == '.')return;
	joong(arr[root - 'A'][0]);
	cout << root;
	joong(arr[root - 'A'][1]);
}
void hoo(char root) {
	if (root == '.')return;
	hoo(arr[root - 'A'][0]);
	hoo(arr[root - 'A'][1]);
	cout << root;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> node >> l >> r;
		arr[node - 'A'][0] = l;
		arr[node - 'A'][1] = r;
	}
	jeon('A');
	cout << '\n';
	joong('A');
	cout << '\n';
	hoo('A');
	return 0;
}