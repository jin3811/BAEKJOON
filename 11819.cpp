#include <bits/stdc++.h>
using namespace std;

uint64_t sol(__int128_t a, __int128_t b, __int128_t mod){
    if (!b) return 1;
    else if(b == 1) return a;
    else {
        __int128_t ret = sol(a, b/2, mod);
        if(b & 1) return (a * ((ret * ret) % mod)) % mod;
        else return (ret * ret) % mod;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    uint64_t a, b, mod;
    cin >> a >> b >> mod;
    cout << sol(a % mod, b, mod);
}