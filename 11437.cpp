#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n,m;
vector<vector<int>> tree, graph;
vector<pair<int,int>> query;

void init(int st, int p, int h){
	if(tree[st][1] != -1) return;
	tree[st][0] = p, tree[st][1] = h;
	for(int g : graph[st]) {
		init(g, st, h+1);
	}
}

void input(){
	int a, b;
	cin >> n;
	graph.resize(n + 1);
	tree.resize(n + 1, vector<int>(2, -1));
	for (int i = 1; i < n; i++){
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cin >> m;
	query.resize(m);
	for(auto& [x, y] : query) {
		cin >> x >> y;
	}
	init(1,0,1);
}

void pull_up(int& a, int& b){
	while(tree[a][1] != tree[b][1]) a = tree[a][0];
}

void sol() {
	for(auto& [a, b] : query) {
		if (tree[a][1] > tree[b][1]) pull_up(a, b);
		else if(tree[a][1] < tree[b][1]) pull_up(b, a);
		
		while(a != b) {
			a = tree[a][0];
			b = tree[b][0];
		}
		
		cout << a << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}