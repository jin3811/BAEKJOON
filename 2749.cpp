#include <iostream>
#define SIZE 1500000
#define MOD 1000000
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long int n;
    int arr[SIZE] = {0, 1};

    for (int i = 2; i < SIZE; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % MOD;
    
    cin >> n;
    cout << arr[n % SIZE];
}