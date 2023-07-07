#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m = 0; // 남성
    int w = 0; // 여성
    int temp_diff = 0; // 현재 차이
    int diff; // 최대 차이
    string line; 

    cin >> diff >> line;

    for(int i = 0; i < line.length(); i++) {
        if(line[i] == 'M') m++;
        else w++;
        temp_diff = abs(m - w);

        if(temp_diff > diff) {
            if(i == line.length() - 1) { // 맨 마지막 사람인 경우 뒷사람이 없으니 그냥 들여보내지 않는다.
                if(line[i] == 'M') m--;
                else w--;
                break;
            }
            else {
                if(line[i] == line[i + 1]) {
                    if(line[i] == 'M') m--;
                    else w--;
                    break;
                }
                else {
                    if(line[i] == 'M') m--;
                    else w--;
                    swap(line[i], line[i + 1]);
                    i--;
                }
            }
        }
    }
    cout << m + w;
}