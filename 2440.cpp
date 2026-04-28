#include <iostream>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    for(; t; t--) {
        for(int j = 0; j < t; j++) cout << '*';
        cout << '\n';
    }
}