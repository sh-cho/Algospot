#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

//const int INF = 987654321;


int n;
int triangle[100][100], cache[100][100], countCache[100][100];

int path2(int y, int x) {
	//base
	if (y == n - 1) return triangle[y][x];

	int& ret = cache[y][x];
	if (ret != -1) return ret;
	return ret = max(path2(y + 1, x), path2(y + 1, x + 1)) + triangle[y][x];
}

int count(int y, int x) {
	if (y == n - 1) return 1;

	int& ret = countCache[y][x];
	if (ret != -1) return ret;
	ret = 0;

	if (path2(y + 1, x + 1) >= path2(y + 1, x)) ret += count(y + 1, x + 1);
	if (path2(y + 1, x + 1) <= path2(y + 1, x)) ret += count(y + 1, x);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		memset(cache, -1, sizeof(cache));
		memset(countCache, -1, sizeof(countCache));

		cin >> n;
		for (int _y = 0; _y < n; ++_y) 
			for (int _x = 0; _x <= _y; ++_x)
				cin >> triangle[_y][_x];

		cout << count(0, 0) << '\n';
	}


	return 0;
}