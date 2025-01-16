/**
 * boj/16953 sol1
 * 그래프탐색문제이다.
 * (sol1) 첫 풀이는 제일 큰값에서 처리해나면 제일 빨리 나올 것이라 생각하여 큐가 아닌 우선순위큐로 처리했다. bfs를 좀 변형한 느낌이다.
 * 
 * ac를 받은 후, 다른 풀이를 보며 알게 되었다.
 * 이런 류의 문제는 같은 값을 여러번 탐색하는 경우를 유의해야하는데, 해당 문제의 조건으로는 같은 값이 나올 수 없다.
 * b에 도달하기 위한 여러 방법이 있다면, 같은 숫자를 만드는데 다른 조합을 쓰더라도 만들 수 있어야만 한다.
 * 하지만 2를 곱하는 것(P작업)은 짝수를 만들어내고, 뒤에 1을 추가하는 것(Q작업)은 홀수를 만들어내는 작업이다.
 * b가 1의자리가 1인 홀수라면 이는 반드시 이전 숫자에서 Q작업을 했다는 뜻이 되며, P작업으로는 해당 숫자를 만들어낼 수 없다.
 * b 이전의 숫자가 1의자리가 1인 홀수/짝수인 경우에도 P,Q작업은 하나로 결정되며 이는 다음과 같은 결론을 만들 수 있다.
 * 조건을 여러번 섞어 쓰더라도 같은 값은 나올 수 없으며, 이는 a -> b로 가는 루트는 유일하다는 뜻이 된다.
 * 
 * 여기서 내 풀이를 개선하는 방법과 다른 풀이가 나오게 된다.
 * (sol2) 첫 풀이는 bfs에 우선순위큐를 쓰는 방법이었지만, a->b로 가는 루트가 유일하다면 dfs로 간단하게 작성이 가능해진다. 물론 그래프 문제이기 때문에 bfs도 얼마든지 가능하다.
 * (sol3) 다른 풀이는 a->b로 가는 루트가 유일함을 보일때 쓴 방법으로 a->b를 만드는게 아니라 b->a를 그리디하게 작성하는 것이다.
 */
#include <bits/stdc++.h>
using ll = int64_t;
using namespace std;

ll a, b;

void sol1() {
	ll ans = -1;
	priority_queue<pair<ll, ll>> pq;
	pq.push({a * 2, 2});
	pq.push({a * 10 + 1, 2});

	while(!pq.empty()) {
		auto [cur, cnt] = pq.top();
		pq.pop();

		if (cur == b) {
			if (ans == -1) ans = cnt;
			else ans = min(ans, cnt);
			break;
		}
		else if (cur < b){
			pq.push({cur * 2, cnt + 1});
			pq.push({cur * 10 + 1, cnt + 1});
		}
		else {
			continue;
		}
	}

	cout << ans;
}

int sol2(ll st, int cnt) {
	if (st > b) return -1;
	if (st == b) return cnt;

	return max(sol2(st * 2, cnt+1), sol2(10 * st + 1, cnt+1));
}

void sol3() {
	int ans = 1;
	while (b > a) {
		if (b % 2 == 0) b /= 2;
		else if (b % 10 == 1) b /= 10;
		else break;
		++ans;
	}
	if (b == a) cout << ans;
	else cout << -1;
}

void sol() {
	// sol1();
	// cout << sol2(a, 1);
	sol3();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b;
	sol();
}