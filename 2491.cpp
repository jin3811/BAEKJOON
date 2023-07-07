#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

void input() {
    cin >> n;
    v.resize(n);
    for (int& x : v) cin >> x;
}

int getMaxIncrease() {
    int len = 1, maxLen = 1;

    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1] > v[i]) len = 1;
        else len++;
		
        maxLen = max(len, maxLen);
    }

    return maxLen;
}

int getMaxDecrease() {
    int len = 1, maxLen = 1;

    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1] < v[i]) len = 1;
        else len++;

        maxLen = max(len, maxLen);
    }

    return maxLen;
}

void sol() {
    #ifndef BOJ
    cout << "inc: " << getMaxIncrease() << endl ;
    cout << "dec: " << getMaxDecrease() << endl;
    #endif

    cout << max(getMaxIncrease(), getMaxDecrease());
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}