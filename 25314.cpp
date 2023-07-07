#include <iostream>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int byte;  
    cin >> byte;

    for(int i = 0; i < byte / 4; i++) {
        cout << "long ";
    }
    cout << "int";
}