#include <iostream>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    int sum = 0;
    while(true) {
        cin >> a;
        if (cin.eof()) break;
        sum += a;
    }
    cout << sum;
}