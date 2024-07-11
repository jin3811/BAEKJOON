#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int n;
vector<tuple<int, int, int>> elem_range;

void input() {
    int r1, r2;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> r1 >> r2;
        // elem_range[i] = {r1 - r2, r1 + r2};
    }

}

void sol() {
    vector<int> res;
    for (int i = 1 ; i <= n; i++) {
        res.clear();
        res.push_back(i); // 자기 자신은 들어갈거 아녀

        for (int j = 1; j <= n; j++) {
            if (i == j) continue;


        }
    }
}

int main() {
    // cin.tie(0)->sync_with_stdio(false);
    // input();
    // sol();

    vector<tuple<int, int, int>> a = {{1,1,1}, {2,2,2}};
    sort(ALL(a));
}