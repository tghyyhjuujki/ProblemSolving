//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
 
long long n, m, ret, MAX = 0, mid;
long long arr[1000000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (MAX < arr[i]) MAX = arr[i];
	}
	long long left = 0, right = MAX;

	while(left<=right){
		mid = (left + right) / 2;
		long long temp = 0;
		for (int i = 0; i < n; i++) {
			if (mid < arr[i]) temp += arr[i] - mid;
		}
		if (temp >= m) {
			if (ret < mid) ret = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ret;
	return 0;
}