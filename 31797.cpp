/**
 * boj/31797
 * 입력은 참가자의 손이 몇번째인지가 아니라, 어느 높이에 있는지를 알려준다.
 * 이는 다음과 같은 입력이 가능하다는 뜻이다.
 * 3 3
 * 1 100
 * 2 200
 * 3 300
 * 이 역시 유효한 입력이기 때문에 이에 유념하면서 처리해야한다.
 * 참가자가 m명이면 손은 2m개이기 때문에, n층의 손 위치는 n-2m과 동치이다.
 */
#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int n, m;
vector<pair<int,int>> v;

void input() {
	int l, r;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> l >> r;
		v.push_back({l, i});
		v.push_back({r, i});
	}
	sort(ALL(v));
}

void sol() {
	while(n > 2 * m) n -= 2 * m;
	cout << v[n - 1].second;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}