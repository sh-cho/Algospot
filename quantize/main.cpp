#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;



// A[]: ����ȭ �ؾ� �� ���� (���ĵ� ����)
// pSum[]: �κ���. pSum[i]�� A[0]..A[i]�� ��
// pSqSum[]: ������ �κ���. pSqSum[i]�� A[0]^2 ... A[i]^2 �� ��
int n, s;
int A[101], pSum[101], pSqSum[101];
int cache[101][11];

void precalc() {
	//A�� �����ϰ� �� �κ����� ���
	sort(A, A + n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];

	for (int i = 1; i < n; ++i) {
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}

int minError(int lo, int hi) {
	//A[lo], A[hi] ������ �ϳ��� ���� ǥ���� ���� �ּ� ������ ��
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);

	int m = int(0.5 + (double)sum / (hi-lo+1));

	int ret = sqSum - 2*m*sum + m*m*(hi-lo+1);

	return ret;
}

int quantize(int from, int parts) {
	// base: ��� ���ڸ� �� ����ȭ���� ��
	if (from == n) return 0;

	// base: ���ڴ� ���Ҵµ� �� ���� �� ���� ��, INF ��ȯ
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