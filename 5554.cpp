#include <iostream>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int secTotal = 0;
    int temp;
    for (int i = 0; i < 4; i++) {
        cin >> temp;
        secTotal += temp;
    }
    cout << secTotal / 60 << '\n' << secTotal % 60;
}