#include <bits/stdc++.h>
using namespace std;

int child, snackCnt;
vector<int> snack;

void input() {
    cin >> child >> snackCnt;
    snack.resize(snackCnt);
    for (int& x : snack) cin >> x;
    sort(snack.begin(), snack.end());
}

int checkCnt(int x) {
    int cnt = 0;
    for (int len : snack) cnt += len / x;
    return cnt;
}

void sol() {
    int st = 1, ed = snack[snackCnt - 1];
    int mid, result = 0;
    while (st <= ed) {
        mid = (st + ed) / 2;

        if (child <= checkCnt(mid)) {
            st = mid + 1;
            result = mid;
        }
        else {
            ed = mid - 1;
        }
    }
    cout << result;
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}