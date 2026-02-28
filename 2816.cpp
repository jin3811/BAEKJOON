/*
 * boj/2816
 * 
 * 버튼 누르는 횟수를 최소로 하라는 말은 없었잖아? + 스페셜 저지(보통 해가 여러개라는 뜻)
 * 최소로 하라 했다면 다익스트라나 bfs를 써야했을 듯
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> tv;

void input() {
	cin >> n;
	tv.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> tv[i];
	}
}

void sol() {
	string ans;
	int cur_pos = 0;

	// 우선 kbs2을 맨 처음으로 올린다.
	while(tv[cur_pos] != "KBS2") cur_pos++;
	ans.append(string(cur_pos, '1'));
	ans.append(string(cur_pos, '4'));
	for(; cur_pos; cur_pos--) {
		swap(tv[cur_pos], tv[cur_pos-1]);
	}

	// 다음 kbs1을 맨 처음으로 올리면 kbs2가 자연스레 밀리면서 kbs1, kbs2순이 된다.
	while(tv[cur_pos] != "KBS1") cur_pos++;
	ans.append(string(cur_pos, '1'));
	ans.append(string(cur_pos, '4'));

	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}