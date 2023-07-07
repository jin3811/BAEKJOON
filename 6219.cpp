#include <iostream>
#include <vector>
using namespace std;

bool isTrue(int target, const int n) {
    while (target) {
        if (target % 10 == n) return true;
        else target /= 10;
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, d;
    int cnt = 0;
    cin >> a >> b >> d;
    vector<bool> seive(b+1, true);
    
    for (int i = 2; i <= b; i++) {
        if (seive[i]) {
            for (int j = 2; i * j <= b; j++)
                seive[i * j] = false;
        }
    }

    for (int i = a; i <= b; i++) {
        if (seive[i] && isTrue(i, d)) ++cnt;
    }
    cout << cnt;
}