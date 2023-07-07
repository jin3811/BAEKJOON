#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    string str;
    string token;

    cin >> t;
    cin.ignore();

    while (t--) {
        getline(cin, str);
        stringstream sstream(str);
        while (getline(sstream, token, ' ')) {
            reverse(token.begin(), token.end());
            cout << token << ' ';
        }
        cout << '\n';
    }
}