#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int t;
    int height, weight;
    int result;
    vector<pair<int, int>> v;

    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> weight >> height;
        v.push_back(make_pair(weight, height));
    }

    for (int i = 0; i < t; i++) {
        result = 1;

        for (int j = 0; j < t; j++){
            if (i == j) continue;
            if (v[i].first < v[j].first && v[i].second < v[j].second)
            result++;
        }
        cout << result << ' ';
    }
}