#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;



// A[]: 양자화 해야 할 수열 (정렬된 상태)
// pSum[]: 부분합. pSum[i]는 A[0]..A[i]의 합
// pSqSum[]: 제곱의 부분합. pSqSum[i]는 A[0]^2 ... A[i]^2 의 합
int n, s;
int A[101], pSum[101], pSqSum[101];
int cache[101][11];

void precalc() {
	//A를 정렬하고 각 부분합을 계산
	sort(A, A + n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];

	for (int i = 1; i < n; ++i) {
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}

int minError(int lo, int hi) {
	//A[lo], A[hi] 구간을 하나의 수로 표현할 때의 최소 오차의 합
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);

	int m = int(0.5 + (double)sum / (hi-lo+1));

	int ret = sqSum - 2*m*sum + m*m*(hi-lo+1);

	return ret;
}

int quantize(int from, int parts) {
	// base: 모든 숫자를 다 양자화했을 때
	if (from == n) return 0;

	// base: 숫자는 남았는데 더 묶을 수 없을 때, INF 반환
	if (parts == 0) return INF;

	int& ret = cache[from][parts];
	if (ret != -1) return ret;
	ret = INF;

	for (int partSize=1; from+partSize<=n; ++partSize)
		ret = min(ret, minError(from, from+partSize-1)+quantize(from+partSize, parts-1));

	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		memset(cache, -1, sizeof(cache));

		cin >> n >> s;
		for (int i = 0; i < n; ++i)
			cin >> A[i];

		precalc();
		cout << quantize(0, s) << '\n';
	}

	return 0;
}