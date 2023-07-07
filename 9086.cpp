#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    string str;
    cin >> tc;
    while(tc--) {
        cin >> str;
        cout << *str.begin() << *str.rbegin() << endl;
    }
}