#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int title = 666;
    int cnt = 0;
    int n;
    string str;

    cin >> n;
    while(true) {
        str = to_string(title);

        if(str.find("666") != string::npos)
            ++cnt;
        
        if (cnt == n) break;
        
        ++title;
    }
    cout << title;
}