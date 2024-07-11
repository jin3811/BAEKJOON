#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int k, l, n;
string record;
bool is_using = false;
vector<int> answer;

void mode_change(int time) {
    is_using = !is_using;
    if (!is_using) {
        answer.push_back(time);
    }
}

void sol() {

    


    for (int& x : answer) cout << x << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> k >> l >> n >> record;
    sol();
}