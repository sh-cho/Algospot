#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;


const int MAX_N = 1000;

int n, m;
double cache[MAX_N][2 * MAX_N + 1];

//달팽이가 days일동안 climbed 미터를 올라왔다고 했을 때
//m일 전까지 n미터를 기어올라갈 수 있는 확률
//1m 올라갈 확률 75%, 2m 올라갈 확률 25%
double climb2(int days, int climbed) {
	//base: m일이 모두 지난 경우
	if (days == m) return (climbed>=n?1:0);

	double& ret = cache[days][climbed];
	if (ret != -1.0) return ret;
	return ret = 0.25 * climb2(days + 1, climbed + 1) + 0.75 * climb2(days + 1, climbed + 2);
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		for (auto& r : cache)
			for (auto& c : r)
				c = -1.0;

		cin >> n >> m;
		cout.precision(10);
		cout << fixed << climb2(0, 0) << '\n';
	}


	return 0;
}