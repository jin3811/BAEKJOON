#include <bits/stdc++.h>
using namespace std;

string input;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

void sol() {
	stringstream sstream(input);
	vector<int> v;
	string token;
	while(getline(sstream, token, ':')) {
		v.push_back(stoi(token));
	}
	int g = gcd(v[0], v[1]);
	cout << v[0]/g << ":" << v[1]/g;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> input;
	sol();
}