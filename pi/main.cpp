#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
string N;
int cache[10002];


// N[a, b] 구간 난이도 반환
int classify(int a, int b) {
	// 숫자조각 가져오기
	string M = N.substr(a, b-a+1);

	// 난이도 1
	if (M == string(M.size(), M[0])) return 1;

	
	// 난이도 2 (등차수열) -> 공차 1, -1인 경우
	// 난이도 5 (등차수열) -> 그 외
	bool progressive = true;	//등차수열인지
	for (int i = 0; i < M.size() - 1; ++i)
		if (M[i + 1] - M[i] != M[1] - M[0]) {
			progressive = false;
			break;
		}

	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;


	// 난이도 4 (번갈아 나타남)
	bool alternating = true;	//번갈아 나타나는지
	for (int i=0; i<M.size(); ++i)
		if (M[i] != M[i % 2]) {
			alternating = false;
			break;
		}

	if (alternating) return 4;
	if (progressive) return 5;
	return 10;
}

int memorize(int begin) {
	// base : 수열의 끝에 도달했을 때
	if (begin == N.size()) return 0;

	// memoization
	int& ret = cache[begin];
	if (ret != -1) return ret;
	ret = INF;


	for (int L=3; L<=5; ++L)
		if (begin+L <= N.size())
			ret = min(ret, memorize(begin+L) + classify(begin, begin+L-1));

	return ret;
}



int main() {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;

	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		cout << memorize(0) << '\n';
	}


	return 0;
}