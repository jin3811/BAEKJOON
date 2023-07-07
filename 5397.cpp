#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    string line;
    list<char> password;
    list<char>::iterator cursor;

    cin >> t;
    cin.ignore();

    while(t--){
        cin >> line;
        password.clear();
        cursor = password.begin();

        for(const auto& command : line) {
            if(command == '<'){
                if(distance(password.begin(), cursor) > 0) cursor--;
            }
            else if(command == '>'){
                if(distance(cursor, password.end()) > 0) cursor++;
            }
            else if(command == '-'){
                if(cursor != password.begin()) cursor = password.erase(--cursor);
            }
            else {
                cursor = password.insert(cursor, command);
                cursor++;
            }
        }

        for(const auto& x : password) {
            cout << x;
        }
        cout << '\n';
    }   
}