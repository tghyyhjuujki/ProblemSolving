#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int N;
double ret;
pair<long long, long long> ary[10001];

double get_size(int a, int b, int c) {
	return (double)(ary[a].first * ary[b].second - ary[b].first * ary[a].second + 
		ary[b].first * ary[c].second - ary[c].first * ary[b].second + 
		ary[c].first * ary[a].second - ary[a].first * ary[c].second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ary[i].first >> ary[i].second;
	}

	for(int i=1;i<N-1;i++) {
		ret += get_size(0, i, i+1);
	}

	ret = abs(ret);
	cout << fixed;
	cout.precision(1);
	cout << ret / 2;
	return 0;
}