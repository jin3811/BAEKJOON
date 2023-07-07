#include <bits/stdc++.h>
using namespace std;

const string korea = "KOREA";
const string yonsei = "YONSEI";
int k_idx = 0, y_idx = 0;
string input;

void sol() {
    for (char elem : input) {
        if (elem == korea[k_idx]) k_idx++;
        if (elem == yonsei[y_idx]) y_idx++;

        if (k_idx == korea.length()) {
            cout << korea;
            return;
        }
        else if (y_idx == yonsei.length()) {
            cout << yonsei;
            return;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> input;
    sol();
}