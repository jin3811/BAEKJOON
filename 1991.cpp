#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
vector<pair<int,int>> tree;

void input() {
	char r, cr, cl;
	cin >> n;
	tree.resize(n);

	for(int i = 0; i < n; i++) {
		cin >> r >> cl >> cr;

		tree[r - 'A'].first  = cl == '.' ? -1 : cl - 'A';
		tree[r - 'A'].second = cr == '.' ? -1 : cr - 'A';
	}
}

void preorder(int r) {
	if (r == -1) return;

	auto& [cl, cr] = tree[r];

	cout << (char)(r + 'A');
	preorder(cl);
	preorder(cr);
}

void inorder(int r) {
	if (r == -1) return;
	auto& [cl, cr] = tree[r];

	inorder(cl);
	cout << (char)(r + 'A');
	inorder(cr);
}

void postorder(int r) {
	if (r == -1) return;
	auto& [cl, cr] = tree[r];

	postorder(cl);
	postorder(cr);
	cout << (char)(r + 'A');
}

void sol(){
	preorder(0); cout << '\n';
	inorder(0); cout << '\n';
	postorder(0); cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input();
	sol();
}