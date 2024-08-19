#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n, k;
string num;

void sol() {
	stack<char> st;
	string answer;
	int len = n - k;

	for(char n : num) {
		if (!st.empty() && k && st.top() < n) {
			while (!st.empty() && k && st.top() < n) {
				st.pop();
				k--;
			}
		}
		st.push(n);
	}

	while(!st.empty()) {
		answer += st.top();
		st.pop();
	}
	
	reverse(ALL(answer));
	cout << answer.substr(0, len);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k >> num;
	sol();
}