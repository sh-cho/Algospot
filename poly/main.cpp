#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

const int MOD = 10 * 1000 * 1000;

int cache[101][101];


int poly(int n, int first) {
	if (n == first) return 1;

	int& ret = cache[n][first];
	if (ret != -1) return ret;
	ret = 0;

	for (int second = 1; second <= n - first; ++second) {
		int add = second + first - 1;
		add *= poly(n - first, second);
		add %= MOD;

		ret += add;
		ret %= MOD;
	}

	return ret;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cache, -1, sizeof(cache));
	
	int c, n;
	cin >> c;
	while (c--) {
		cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			sum += poly(n, i);
			sum %= MOD;
		}
		cout << sum << '\n';
	}


	return 0;
}