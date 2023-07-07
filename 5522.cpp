#include <iostream>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int temp, sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> temp;
        sum += temp;
    }
    cout << sum;
}