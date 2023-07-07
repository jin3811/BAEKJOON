#include <bits/stdc++.h>
using namespace std;

string doc, word;

bool equal(int start) {
    for (int i = 0; i < word.size(); i++)
        if (doc[start + i] != word[i]) return false;
    return true;
} 

void sol() {
    int answer = -1;
    int cnt;
    for (int i = 0; i < doc.length(); i++) {
        cnt = 0;
        for (int j = i; j < doc.length();) {
            if (equal(j)) {
                cnt++;
                j += word.size();
            }
            else j++;
        }
        answer = max(answer, cnt);
    }
    cout << answer;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    getline(cin, doc);
    getline(cin, word);
    sol();
}