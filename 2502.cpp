#include <bits/stdc++.h>
using namespace std;

array<uint64_t, 31> arr = {0, 1};

int fibo(int n){
    if (n <= 1) return n;
    else if (arr[n]) return arr[n];
    else{
        arr[n] = fibo(n - 1) + fibo(n - 2);
        return arr[n];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    bool flag = true;
    int d, k, a, b, temp;
    cin >> d >> k;
    
    int p = fibo(d - 2);
    int q = fibo(d - 1);

    for(a = 1; flag; a++) {
        for(b = a; temp = p*a + q*b, temp <= k; b++) {
            if(temp == k) {
                flag = false;
                break;
            }
        }
    }
    cout << a-1 << '\n' << b;
}