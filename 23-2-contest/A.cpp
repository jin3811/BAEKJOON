#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tc, n, answer;
    string input;
    cin >> tc;
    for (int i = 1;i <= tc; i++) {
        answer = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin.ignore();
            cin >> input;
            if (input == "가위바위보") answer++;
        }
        cout << "Case #" << i << " : " << answer << endl;
    }
}