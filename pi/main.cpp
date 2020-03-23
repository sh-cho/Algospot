#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
string N;

// N[a, b] ���� ���̵� ��ȯ
int classify(int a, int b) {
	// �������� ��������
	string M = N.substr(a, b-a+1);

	// ���̵� 1
	if (M == string(M.size(), M[0])) return 1;

	
	// ���̵� 2 (��������) -> ���� 1, -1�� ���
	// ���̵� 5 (��������) -> �� ��
	bool progressive = true;	//������������
	for (int i = 0; i < M.size() - 1; ++i)
		if (M[i + 1] - M[i] != M[1] - M[0]) {
			progressive = false;
			break;
		}

	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;


	// ���̵� 4 (������ ��Ÿ��)
	bool alternating = true;	//������ ��Ÿ������
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