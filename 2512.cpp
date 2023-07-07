#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
int st = 1, ed = -1;

void input() {
    ed = -1;
    cin >> n;
    v.resize(n);
    for(int& x : v) {
        cin >> x;
        ed = max(ed, x);
    }
    cin >> m;
}

inline int budget(int maximum) {
    int result = 0;
    for(int& x : v) {
        if (x <= maximum) result += x;
        else result += maximum;
    }
    return result;
}

void solution() {
    int mid;
    int result = 0;

    while(st <= ed) {
        mid = (st + ed) / 2.;
        if (budget(mid) > m) {
            ed = mid - 1;
        }
        else {
            result = mid;
            st = mid + 1;
        }
    }
    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solution();
}