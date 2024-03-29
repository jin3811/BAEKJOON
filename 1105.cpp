/**
 * https://www.acmicpc.net/problem/1105
 * C++
 * 
 * 풀이전략 : 그리디
 * 처음 봤을땐 백트래킹같은 문제일 것 같았지만, 범위를 보자마자 그건 아니란걸 바로 알았다.
 * 탐색 범위를 줄여보기 위해, 각 자리수를 8은 1, 나머지는 0으로 재구성하면 이진수의 형태로 나타낼수 있어,
 * 범위를 좁힐 수 있을 것이라 생각했다. 하지만, 이는 예제 4에서 막히게 되므로 적절한 방법이 아녔다
 * 
 * 자릿수가 다른 경우를 생각해보면, 답은 무조건 0이 된다. 
 * 88과 888 사이에는 100이 존재할것이니까. 어떤 두 숫자를 가져와도, 자릿수가 넘어가면서 8이 없는 수가 생긴다.
 * 
 * 자릿수가 같다면이 문제이다.
 * 1788 1888 의 경우를 생각해보면 당장 생각해도 1800이 제일 적은 수일 것이다. 
 * 다른 숫자가 나타나는 시점에서, 뒤의 숫자들은 의미가 없어진다. 자릿수가 바뀌면서 00이 될거니까 말이다.
 * 
 * 이제 다른 숫자가 나타날때까지 세면서, 8이 나타나는 갯수를 세주면 된다.	
*/

#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int r, l;

void sol() {
	string str_r = to_string(r);
	string str_l = to_string(l);
	int res = 0;

	// 자리수가 다르면 무조건 10^n이 등장한다 => 0개 존재
	if (str_r.length() != str_l.length()) {
		cout << 0;
		return;
	}

	for (int i = 0; i < str_r.length(); i++) {
		if (str_l[i] != str_r[i]) {
			cout << res;
			return;
		}

		if (str_l[i] == '8') res++;
	}
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> r >> l;
	sol();
}