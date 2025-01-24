/**
 * boj/1759
 * 
 * 익숙한 N과 M 문제의 냄새가 난다. 백트래킹으로 처리하며 자음 2개 이상, 모음 1개 이상의 조건을 지키면 된다.
 */
#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int l, c;
string pwd, vowels, consonants;

void input() {
	string all_vowels = "aeiou";
	char a;
	cin >> l >> c;

	while(pwd.length() < c) {
		cin >> a;
		if (a != ' ') pwd += a;
		if (all_vowels.find(a) != string::npos) {
			vowels += a;
		}
		else {
			consonants += a;
		}
	}

	sort(ALL(pwd));
	sort(ALL(vowels));
}

void sol(int idx, string output) {
	if (output.length() == l) {
		int vo_count = 0, con_count = 0;

		for(char& v : vowels) {
			if (output.find(v) != string::npos) {
				vo_count++;
				break;
			}
		}

		for(char& c : consonants) {
			if (con_count == 2) {
				break;
			}
			if (output.find(c) != string::npos) {
				con_count++;
			}
		}

		if (vo_count == 1 && con_count == 2) {
			cout << output << endl;
		}

		return;
	}
	else if (idx >= c) {
		return;
	}

	for(; idx < c; idx++) {
		sol(idx + 1, output + pwd[idx]);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol(0, "");
}