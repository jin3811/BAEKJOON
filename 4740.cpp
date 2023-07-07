#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;

    while (true) {
        getline(cin, str);
        if (str == "***") break;
        reverse(str.begin(), str.end());
        cout << str << '\n';
    }
}