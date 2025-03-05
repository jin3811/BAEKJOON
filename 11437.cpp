// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;

// int n,m;
// vector<vector<int>> tree, graph;
// vector<pair<int,int>> query;

// void init(int st, int p, int h){
// 	if(tree[st][1] != -1) return;
// 	tree[st][0] = p, tree[st][1] = h;
// 	for(int g : graph[st]) {
// 		init(g, st, h+1);
// 	}
// }

// void input(){
// 	int a, b;
// 	cin >> n;
// 	graph.resize(n + 1);
// 	tree.resize(n + 1, vector<int>(2, -1));
// 	for (int i = 1; i < n; i++){
// 		cin >> a >> b;
// 		graph[a].push_back(b);
// 		graph[b].push_back(a);
// 	}
// 	cin >> m;
// 	query.resize(m);
// 	for(auto& [x, y] : query) {
// 		cin >> x >> y;
// 	}
// 	init(1,0,1);
// }

// void pull_up(int& a, int& b){
// 	while(tree[a][1] != tree[b][1]) a = tree[a][0];
// }

// void sol() {
// 	for(auto& [a, b] : query) {
// 		if (tree[a][1] > tree[b][1]) pull_up(a, b);
// 		else if(tree[a][1] < tree[b][1]) pull_up(b, a);
		
// 		while(a != b) {
// 			a = tree[a][0];
// 			b = tree[b][0];
// 		}
		
// 		cout << a << endl;
// 	}
// }

// int main() {
// 	cin.tie(0)->sync_with_stdio(0);
// 	input();
// 	sol();
// }
// 위 코드는 https://www.acmicpc.net/board/view/148254 의 논의로 인해 시간초과가 나게 된 코드

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define MAX_A 20 // log(max(n)) = log(100k) = 17이니 여유롭게 20으로 설정

int n,m;
vector<vector<int>> tree, graph;
vector<int> depths;
vector<pair<int,int>> query;

void make_tree(int st, int p, int h) {
	tree[st][0] = p, depths[st] = h;

	for(int g : graph[st]) {
		if (g == p) continue;
		make_tree(g, st, h+1);
	}
}

void make_ancestor() {
	for (int ancestor = 1; ancestor <= MAX_A; ancestor++) {
		for (int node = 1; node <= n; node++) {
			tree[node][ancestor] = tree[tree[node][ancestor - 1]][ancestor - 1];
		}
	}
}

void init(){
	make_tree(1, 0, 1);
	make_ancestor();
}

void input(){
	int a, b;
	cin >> n;
	graph.resize(n + 1);
	tree.resize(n + 1, vector<int>(MAX_A + 1));
	depths.resize(n + 1, -1);
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
	init();
}

void sol() {
	for(auto& [target, goal] : query) {
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
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}