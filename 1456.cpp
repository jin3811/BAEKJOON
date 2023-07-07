#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MAX = 10000001;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<ll> prime;
    bool* seive = new bool[MAX];
    fill(seive, seive + MAX, true);
    seive[0] = seive[1] = false;

    for(ll i = 2; i < MAX; i++) {
        if(seive[i]) {
            prime.push_back(i);
            for(ll j = 2; i * j < MAX; j++) {
                seive[i*j] = false; 
            }
        }
    }
    delete[] seive;
    ll a, b;
    ll temp;
    int cnt = 0;

    cin >> a >> b;
    for(const ll& x : prime) {
        temp = x;
        while(temp <= b / x){
            temp *= x;
            if (temp >= a) cnt++;
        }
    }
    cout << cnt;
}