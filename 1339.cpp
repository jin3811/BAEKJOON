#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> words;

void input() {
    cin >> n;
    words.resize(n);
    for(auto& x : words) cin >> x;
}

void sol() {
    int use_alpha[26] = {0, };
    int result = 0;
    int pow;

    for(auto word : words) {
        pow = 1;
        reverse(word.begin(), word.end());
        for(auto ch : word) {
            use_alpha[ch - 'A'] += pow;
            pow *= 10;
        }
    }

    sort(use_alpha, use_alpha + 26, greater<>());
    for(int i = 0; i < 10; i++) {
        result += use_alpha[i] * (9 - i);
    }
    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}