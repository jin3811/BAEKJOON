#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define MAX_A 15

int n,m;
vector<vector<int>> tree, graph;
vector<int> depths;
int target, goal;

void make_tree(int st, int h) {
	depths[st] = h;
	for(int g : graph[st]) make_tree(g, h+1);
}

void make_ancestor() {
	for (int ancestor = 1; ancestor <= MAX_A; ancestor++) {
		for (int node = 1; node <= n; node++) {
			tree[node][ancestor] = tree[tree[node][ancestor - 1]][ancestor - 1];
		}
	}
}

void input(){
	bool root[10001] = {false};
	int a, b;
	cin >> n;
	graph = vector<vector<int>>(n + 1);
	tree = vector<vector<int>>(n + 1, vector<int>(MAX_A + 1));
	depths = vector<int>(n + 1, -1);
	for (int i = 1; i < n; i++){
		cin >> a >> b;
		tree[b][0] = a;
		graph[a].push_back(b);
		root[b] = true;
	}
	cin >> target >> goal;
	for(int i = 1; i <= n; i++) {
		if(!root[i]) {
			make_tree(i, 1);
			break;
		}
	}
	make_ancestor();
}

void sol() {
	// target노드를 goal노드의 높이로 끌어올린다.
	if (depths[target] < depths[goal]){
		swap(target, goal);
	}
	int dh = depths[target] - depths[goal];
	for (int i = MAX_A; i >= 0 && dh; i--) {
		if (dh >= (1 << i)) {
			target = tree[target][i];
			dh -= (1 << i);
		}
	}

	if (target == goal){
		cout << goal << endl;
	}
	else {
		for (int i = MAX_A; i >= 0; i--) {
			if (tree[target][i] != 0 &&
				tree[target][i] != tree[goal][i]) {
				target = tree[target][i];
				goal = tree[goal][i];
			}
		}
		cout << tree[goal][0] << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tc;
	cin >> tc;
	while(tc--) {
		input();
		sol();
	}
}