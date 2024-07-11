#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;

vector<map<string, int>> corpus;
map<string, int> df;
int m, n;

void input() {
    string doc, token;
    corpus.resize(n);

    for (auto& table : corpus) {
        cin >> doc;
        stringstream sstream(doc);
        while (getline(sstream, token, ' ')) {
            if(table.find(token) == table.end()) {
                table[token] = 0;
            }
            else {
                table[token]++;
            }
            
            if(df.find(token) == df.end()) {
                df[token] = 0;
            }
            else {
                df[token]++;
            }
        }
    }
}

int tf(map<int, string>::iterator doc) {

}

void make_tfidf(vector<vector<double>>& tfidf) {

}

void sol(int query) {

    priority_queue<pair<double, string>> pq;

    auto iter = corpus[query].begin();
    
    for (auto& token )
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int query;
    cin >> n >> m;
    input();
    while (n--) {
        cin >> query;
        sol(query);
    }
}