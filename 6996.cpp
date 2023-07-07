#include <bits/stdc++.h>
#define endl '\n'
#define ALL(X) (X).begin(), (X).end()
using namespace std;

void sol(string& a, string& b) {
    cout << a << " & " << b << " are ";
    sort(ALL(a)); sort(ALL(b));
    cout << (a == b ? "" : "NOT ") << "anagrams." << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    string a, b;
    
    cin >> t;
    while(t--) {
        cin >> a >> b;
        sol(a, b);
    }
}