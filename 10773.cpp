#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    vector<int> st;
    int T, temp;
    cin >> T;

    while (T--) {
        cin >> temp;
        if (temp) st.push_back(temp);
        else st.pop_back();
    }
    cout << accumulate(st.begin(), st.end(), 0);
}