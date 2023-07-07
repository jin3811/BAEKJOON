#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare (pair<int, string> user1, pair<int, string> user2) {
    return user1.first < user2.first;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int age;
    string name;
    vector<pair<int, string>> user;
    vector<pair<int, string>>::iterator iter;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> age >> name;
        user.push_back(make_pair(age, name));
    }
    
    stable_sort(user.begin(), user.end(), compare);
    
    for (iter = user.begin(); iter != user.end(); iter++)
        cout << iter->first << ' ' << iter->second << '\n';    
}