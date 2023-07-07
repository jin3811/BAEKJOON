#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

array<array<int, 30>, 30> memo;

int combination(int n, int r) {
    if (memo[n][r]) return memo[n][r];
    else{
        memo[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
        return memo[n][r];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // initialize memoization array
    for(auto& x : memo) fill(x.begin(), x.end(), 0);
    for(int i = 0; i < 30; i++) {
        memo[i][0] = memo[i][i] = 1;
    }

    int tcase, n, r;

    cin >> tcase;
    while(tcase--){
        cin >> r >> n;
        cout << combination(n, r) << endl;
    }
}

// second sol
/*
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tcase, n, r, temp;
    int answer;

    cin >> tcase;
    while(tcase--) {
        answer = 1;
        temp = 1;
        cin >> r >> n;
        for(int i = n; i > n - r; i--) {
            answer *= i;
            answer /= temp++;
        }
        cout << answer << endl;
    }
}
*/