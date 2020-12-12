#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, H, up[100001], down[100001];
	cin >> N >> H;
	for (int i = 0; i < N / 2; i++) cin >> up[i] >> down[i];
	int X = N / 2, part = 0, min_stuck = 200001;
	sort(up, up + X); sort(down, down + X);
	for (int i = 1; i <= H; i++)
	{
		int temp_stuck = 0;
		temp_stuck += distance(lower_bound(down, down + X, i), down + X);
		temp_stuck += distance(lower_bound(up, up + X, H + 1 - i), up + X);
		if (min_stuck > temp_stuck) min_stuck = temp_stuck, part = 1;
		else if (min_stuck == temp_stuck) part++;
	}
	cout << min_stuck << ' ' << part;
	return 0;
}