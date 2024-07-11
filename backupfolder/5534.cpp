#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

string name;
vector<string> signs;

void input() {
    int n;
    cin >> n >> name;
    signs.resize(n);
    for(auto& sign : signs) cin >> sign;
}

bool isVaild(const auto& sign) {
    int idx;

    for(int i = 0; i < sign.length(); i++){
        
    }

    return true;
}

void sol() {
    int answer = 0;
    for (const auto& sign : signs) {
        if (isValid(sign)) answer++;
    }

    cout << answer;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    input();
    sol();
}