#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    ll x, y;
    long double S = 0;
    vector<pair<ll, ll>> v;
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    
    for(int i = 0; i < n - 1; i++) {
        S += v[i].first * v[i + 1].second;
        S -= v[i + 1].first * v[i].second;
    }
    S += v[n - 1].first * v[0].second;
    S -= v[0].first * v[n - 1].second;
    S = S < 0 ? -S : S;
    S /= 2;
    printf("%.1Lf", S);
}