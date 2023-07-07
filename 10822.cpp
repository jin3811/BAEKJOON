#include <iostream>
#include <cstring>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    char str[101];
    int sum = 0;

    cin >> str;
    for (char * i = strtok(str, ","); i != nullptr; i = strtok(nullptr, ","))
        sum += atoi(i);

    cout << sum;
}