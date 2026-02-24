/**
 * boj/17828
 * algo : 그리디
 * 
 * 풀이1:
 * 어짜피 최대한 앞에 작은 수로 채우고, 뒤에 큰 수로 채워간다.
 * 
 * 풀이2:
 * 당장 n과 x로 만들수 있는 문자열을 만든 후, 뒤에 숫자들에 1씩 넘겨준다.
 * 라고 생각하고 있었는데, 풀이2 를 코드로 쓰고 있다가 그럴거면 그냥 A로 된 문자열 만들고
 * 뒤에서부터 Z될때까지 다 더해버리면 끝이네
 */
#include <bits/stdc++.h>
using namespace std;

int n, x;

void sol() {
	if (26 * n < x || n > x) {
		cout << '!';
		return;
	}

	string ans;
	int alpha = 26;
	while (alpha) {
		if (x - alpha < 0 || x - alpha < n - 1) {
			--alpha;
			continue;
		}

		int cnt = x / alpha;
		x -= alpha * cnt;
		n -= cnt;

		while (x < n) {
			--cnt;
			x += alpha;
			++n;
		}
		
		ans.insert(0, string(cnt, alpha + 'A' - 1));
		
	}
	cout << ans;
}

void sol2() {
	if (26 * n < x || n > x) {
		cout << '!';
		return;
	}

	string ans(n, 'A');
	x -= n;
	
	for(int i = n - 1; n >= 0 && x; n--) {
		int dist = min(x, 'Z' - ans[i]);
		x -= dist;
		ans[i] += dist;
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> x;
	sol();
}