#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    int temp;
    int y = 0;
    int m = 0;

    cin >> tc;
    while(tc--) {
        cin >> temp;
        y += (temp / 30 + 1) * 10;
        m += (temp / 60 + 1) * 15;
    }
    if(y < m) cout << "Y " << y;
    else if(y > m) cout << "M " << m;
    else cout << "Y M " << y;
}
