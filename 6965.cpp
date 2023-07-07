#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string line;
    string token;
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        getline(cin, line);
        stringstream sstream(line);
        while (getline(sstream, token, ' ')) {
            cout << (token.length() == 4 ? "****" : token);
            cout << ' ';
        }
        cout << "\n\n";
    }
}