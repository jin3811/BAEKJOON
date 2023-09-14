#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const string vowel = "aeiou";
const string consonant = "bcdfghjklmnpqrstvwxyz";

bool have_vowel(const string& pwd) {
	for (auto v : vowel) {
		if (pwd.find(v) != string::npos) {
			return true;
		}
	}
	return false;
}

bool have_conso_vow_duplicate(const string& pwd) {
	for (int i = 0; i < (int)pwd.length() - 2; i++) {
		if (consonant.find(pwd[i]) != string::npos) {
			if (consonant.find(pwd[i + 1]) != string::npos &&
				consonant.find(pwd[i + 2]) != string::npos) {
				
				return false;
			}
		}
		else {
			if (vowel.find(pwd[i + 1]) != string::npos &&
				vowel.find(pwd[i + 2]) != string::npos) {
				
				return false;
			}
		}
	}
	return true;
}

bool have_letter_duplicate(const string& pwd) {
	for (int i = 0; i < (int)pwd.length() - 1; i++) {
		if (pwd[i] == 'e' || pwd[i] == 'o') {
			continue;
		}
		
		if (pwd[i] == pwd[i + 1]) {
			return false;
		}
	}
	return true;
}

void sol(string& pwd) {
	cout << '<' << pwd << "> ";
	if (have_vowel(pwd) && have_conso_vow_duplicate(pwd) && have_letter_duplicate(pwd)) {
		cout << "is acceptable.";
	}
	else {
		cout << "is not acceptable.";
	}
	cout << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	string pwd;
	while(1) {
		cin >> pwd;
		if (pwd == "end") return 0;
		sol(pwd);
	}
}