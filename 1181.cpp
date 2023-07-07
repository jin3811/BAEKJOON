#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare (string str1, string str2) {
    if (str1.size() == str2.size()) return str1 < str2;
    else return str1.size() < str2.size();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string temp;
    vector<string> words;
    vector<string>::iterator iter;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        words.push_back(temp);
    }
    
    sort(words.begin(), words.end(), compare);
    words.erase(unique(words.begin(), words.end()), words.end()); // 중복제거

    for (iter = words.begin(); iter != words.end(); iter++)
        cout << *iter << '\n';    
}