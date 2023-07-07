#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    array<string, 8> bw = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
    };
    array<string, 8> wb = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
    };

    int n, m, result, cnt;
    int change_bw, change_wb;
    string temp;
    vector<string> v;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    result = n*m;
    for(int i = 0; i <= n - 8; i++) {
        for(int j = 0; j <= m - 8; j++) {
            cnt = change_bw = change_wb = 0;

            for(int k = 0; k < 8; k++) {
                for(int l = 0; l < 8; l++) {
                    if (v[k + i][l + j] != bw[k][l])
                        ++change_bw;

                    if (v[k + i][l + j] != wb[k][l]) 
                        ++change_wb;
                }
            }
            result = min(result, min(change_bw, change_wb));
        }
    }
    cout << result;
}
