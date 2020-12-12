#include <iostream>
using namespace std;

int ret = 0, N, L;
int arr[201][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> L;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[N + i][j] = arr[j][i];
		}
	}

	for (int i = 0; i < 2 * N; ++i) {
		int stack = 1;
		int now, next;
		bool check = true;
		for (int j = 0; j < N - 1; ++j) {
			now = arr[i][j]; next = arr[i][j + 1];
            
			if (now - next > 1 || next - now > 1) {
				check = false; break;
			}
            
			if (now == next) {
				stack++;
				continue;
			}
            
			else if (now > next) {
				for (int k = 1; k <= L; k++) {
					if (j + k == N) {
						check = false; 
						break;
					}
					if (arr[i][j + k] != next) {
						check = false;
						break;
					}
				}
				if (check == true) {
					j = j + L - 1;
					stack = 0;
				}
			}

			else if (now < next) {
				if (stack < L) check = false;
				stack = 1;
			}
			if (check == false) break;
		}
		if (check == true) ret++;
	}
	cout << ret;
	return 0;
}