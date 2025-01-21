/**
 * boj/17451
 * 
 * 이분탐색 문제.
 * 자료형과 최댓값에 주의해야한다. 속도가 모두 10^9 이하라서 int로 잡고 있었는데, 틀렸다고 나와서 고민했다.
 * 도저히 알고리즘에서 틀린거 같진 않아 사람들의 풀이를 뒤져보았다. 
 * 역시 알고리즘이 틀린게 아니라 10^9의 정수배로 통과할수도 있기 때문에 자료형과 high값에 유의해야했다.
 * 
 * 그리고 풀이 보니까 다들 똑같이 역방향 탐색으로 그리디하게 푸는 풀이도 있는 것 같다.
 */
#include <bits/stdc++.h>
using namespace std;
using ll = uint64_t;

int n;
vector<ll> dist;

void input() {
	cin >> n;
	dist.resize(n);
	for(ll& d : dist) cin >> d;
}

bool check(ll velo) {
	for(ll d : dist) {
		if (velo < d) {
			return false;
		}
		velo -= velo % d;
	}
	return true;
}

void sol() {
	ll low = 1, high = 1e18, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (check(mid)) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << low;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}