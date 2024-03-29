#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<int> inputs;

void input() {
    cin >> n;
    inputs.resize(n);
    for(int& x : inputs) cin >> x;
    sort(ALL(inputs));
}

void sol() {
    long long res = 0, i = 0, j;

    // mex(0, 0) = 1
    while(inputs[i] == 0) i++; // 0의 개수를 센다.
    res += (i - 1) * i / 2; // iC2 * mex(0, 0) = (i * i-1 / 2) * 1

    // mex(0, 1) = 2
    j = i;
    while (inputs[j] == 1) j++;
    res += i * (j - i) * 2; 

    // mex(0, 2이상) = 1;
    res += i * (n - j);

    assert(res >= 0);
    cout << res;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    input();
    sol();
}