#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

int m;
string str;

void sol() {
    int l = 0, r = 0, answer = -1;
    map<char, int> key;

    while (r < str.length()) {
        if (l == r || l - r < m)  r++;

        else {
            
            answer = max(answer, r++ - l);
            else l++;
        }
    }

    cout << answer << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    while(1) {
        cin >> m;
        if (!m) break;
        cin.ignore();
        getline(cin, str, '\n');
        sol();
    }
}