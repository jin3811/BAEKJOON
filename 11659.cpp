#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int* arr;
int tcase, len;

void input() {
    int temp;

    cin >> len >> tcase;
    arr = new int[len + 1];
    *arr = 0;
    for (int i = 1; i <= len; i++) {
        cin >> temp;
        arr[i] = arr[i - 1] + temp;
    }
}

void sol() {
    while(tcase--) {
        int l, r;
        cin >> l >> r;
        cout << arr[r] - arr[l - 1] << endl;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}