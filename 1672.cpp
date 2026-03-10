#include <bits/stdc++.h>
using namespace std;

int n;
string nuc;

void input() {
	cin >> n >> nuc;
}

void sol() {
	map<char, int> base = {{'A', 0}, {'G', 1}, {'C', 2}, {'T', 3}};
	array<string, 4> decode = {"ACAG", "CGTA", "ATCG", "GAGT"};

	for(int i = n - 2; i >= 0; i--) {
		nuc[i] = decode[base[nuc[i]]][base[nuc[i+1]]];
		nuc[i + 1] = ' ';
	}
	cout << nuc[0];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}