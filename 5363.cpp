#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<string> yoda;
    string token, line;
    int t;

    cin >> t;
    cin.ignore();
    
    while(t--) {
        yoda.clear();
        getline(cin, line);
        stringstream sstream(line);

        while(getline(sstream, token, ' '))
            yoda.push_back(token);

        rotate(yoda.begin(), yoda.begin() + 2, yoda.end());

        for(const auto& x : yoda) 
            cout << x << ' ';
        
        cout << '\n';
    }
}