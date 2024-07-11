#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string sosu;

void sol() {
	int ten = 1;
	int len = sosu.length()-2;
	int uie = stoi(sosu.substr(2, len));
	for(int i = 0; i < len; i++) {
		ten *= 10;
	}
	cout << "YES" << endl << uie << ' ' << ten;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> sosu;
	sol();
}