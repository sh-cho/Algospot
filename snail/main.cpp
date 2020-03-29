#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;


const int MAX_N = 1000;

int n, m;
double cache[MAX_N][2 * MAX_N + 1];

//�����̰� days�ϵ��� climbed ���͸� �ö�Դٰ� ���� ��
//m�� ������ n���͸� ���ö� �� �ִ� Ȯ��
//1m �ö� Ȯ�� 75%, 2m �ö� Ȯ�� 25%
double climb2(int days, int climbed) {
	//base: m���� ��� ���� ���
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