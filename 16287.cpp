/**
 * boj/16287
 * 
 * 네개의 쌍을 한번에 찾는건 무리가 있기 때문에 7453번 문제처럼 우선 두개의 쌍을 먼저 찾는다.
 * 두개의 쌍을 찾을때에는 중복된 원소를 고르지 않도록 인덱스를 조절한다.
 * 
 * 소포를 정렬한 후, 맨 처음부터 순회하면서 만들어지는 소포의 쌍은, 같은 w'에 대해, 간격이 짧은 조합을 찾아가게 된다.
 * 예를 들어, 1 2 3 4 5 6 에서 5를 만드는 쌍은 (1, 4), (2, 3)이 있다. 점점 오른쪽 숫자의 인덱스가 줄어든다.
 * 이는 남아있는 오른쪽의 소포들을 이용해 다른 쌍을 만드는 경우를 더 많이 찾을 수 있다는 뜻이 된다. 이렇게 찾은 조합을 보고, w1 + w2 = w를 만들기 위한 다른 조합중, 중복되는 소포가 없는지 보면서 찾는다.
 */
#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
using namespace std;

int w, n;
vector<int> parcel;

void input() {
	cin >> w >> n;
	parcel.resize(n);
	for(int& p : parcel) cin >> p;
	sort(ALL(parcel));
}

void sol() {
	vector<pair<int,int>> ab(799995);

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			ab[parcel[i] + parcel[j]] = {i, j};
		}
	}

	for(int w_ab = 3; w_ab <= w / 2; w_ab++) {
		auto& [a, b] = ab[w_ab];
		auto& [c, d] = ab[w - w_ab];
		if (a == -1 || b == -1 || c == -1 || d == -1) continue;

		if (a != c && a != d && b != c && b != d) {
			cout << "YES"; 
			return;
		}
	}
	cout << "NO";
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}