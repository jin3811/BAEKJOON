#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

array<int, 5> tree;

void input() {
    for(int& x : tree) cin >> x;
}

void array_print() {
    for(const int& x : tree) {
        cout << x << ' ';
    }
    cout << endl;
}

void solution() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4 - i; j++) {
            if (tree[j] > tree[j + 1]) {
                swap(tree[j], tree[j + 1]);
                array_print();
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solution();
}