#include <iostream>
#include <string>
#define r 31
#define M 1234567891

using namespace std;

int main () {
    int l, i;
    long long hash = 0, R = 1;
    string str;

    cin >> l >> str;

    for (i = 0; i < str.length(); i++) {
        hash += ((str[i] - 'a' + 1) * R) % M; hash %= M;
        R = (R * r) % M;
    }
    cout << hash;
}