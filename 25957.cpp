#include <bits/stdc++.h>
#define ALL(X) X.begin()+1, X.end()-1
#define endl '\n'
using namespace std;

int n, m;
map<string, string> words;
vector<string> sentence;

void input() {
	string k, v;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		cin >> v;
		k = v;
		if (k.length() > 2UL) sort(ALL(k));
		words[k] = v;
	}

	cin >> m;
	sentence.resize(m);
	for (auto& x : sentence) {
		cin >> x;
		if (x.length() > 2UL) sort(ALL(x));
	}
}

void sol() {
	for (auto& x : sentence) cout << words[x] << ' ';
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	input();
	sol();
}