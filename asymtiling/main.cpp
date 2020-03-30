#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int cache[101];

int tiling(int width) {
	// base: width가 1이하일때
	if (width <= 1) return 1;

	int& ret = cache[width];
	if (ret != -1) return ret;
	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}

int asymmetric(int width) {
	if ((width % 2) == 1)	//홀수
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;

	int ret = tiling(width);
	ret = (ret - tiling(width / 2) + MOD) % MOD;
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
	return ret;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c, n;

	memset(cache, -1, sizeof(cache));
	cin >> c;
	while (c--) {
		cin >> n;
		cout << asymmetric(n) << '\n';
	}


	return 0;
}