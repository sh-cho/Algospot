#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
string N;

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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	return 0;
}