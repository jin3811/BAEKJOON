/**
 * boj/3830
 * 
 * 생긴건 최단거리문제였기 때문에, 최단거리 알고리즘들을 떠올렸다. 또한 무게차이가 없음을 빠르게 알기 위해 각 정점을 union-find 연산으로 미리 알아두고자 했다.
 * 
 * 플로이드는 TLE MLE 동시에 터진다 시간복잡도 O(N^3) 공간복잡도 O(N^2).
 * 다익은 이 문제에 적용하면 1회에 O(MlogN)의 시간복잡도인데, 이를 M번의 쿼리에 대해 실행하기에 N, M모두 10만까지 되기에 안된다. 
 * 벨만포드 역시 O(N^2 * M)이니 안된다. a -> b일때 w라면 b->a는 -w이기 때문에 음수간선의 가능성이 있다
 * BFS를 쓴다 해도 O(N(N+M))이기에 불가능하다
 * 
 * 최단거리 알고리즘은 불가능함을 알 수 있다. 눈길을 유니온 파인드로 돌렸다.
 * 
 * a b w라는 쿼리가 들어오면 a를 b의 자식노드로 두고, 비용을 w로 두었다. b <- a라는 정보가 생기고, cost[a]에는 w를 저장한다. 결국 b <- a의 정보는 집합에 노드가 추가될때마다, 집합의 루트 R <- A일때의 비용을 cost[a]에 저장하도록 한다. 유니온 파인드의 동작 방식에 맞추기 위해서이다.
 * 
 * b와 a가 이미 집합에 포함되어있다면, b와 b의 루트 r_b까지의 무게차이 B (find를 통해 정리됨, B = rb - b)와 a와 a의 루트 r_a까지의 무게차이 A (A = r_a - a), w (b - a) 를 통해 다른 연결되는 간선(a와 b가 연결되면서 생기는 새로운 무게차이)들의 데이터도 정리할 수 있다. 
 * 
 * 이를 merge에 반영하여 적용한다.
 * 
 * find연산에서는 각 정점을 루트에 붙이면서, 이때의 비용을 수정해야한다.
 * root <- b <- a이고 root <- b를 w1, b <- a를 w2라고 하면 find연산을 통해 root <- a로 정리될 것이고, 이때의 비용은 w1 + w2로 수정되어야 한다. 이를 적용한다.
 * 
 */

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

typedef struct Disjoint_set{
	int* tree;
	ll* cost;

	Disjoint_set(int n) {
		tree = new int[n + 1], cost = new ll[n + 1];
		memset(tree, 0xff, sizeof(int) * (n + 1));
		memset(cost, 0, sizeof(ll) * (n + 1));
	}

	void merge(int a, int b, int w) {
		int ra = find(a), rb = find(b); // find를 먼저 수행하여, 간선의 정보를 모두 업데이트해준다.
		ll ac = cost[a], bc = cost[b];
		if (ra == rb) return;

		tree[rb] += tree[ra];
		tree[ra] = rb;

		// (r_b - b) - (r_a - a) + b - a = r_b - r_a 를 구할 수 있다. 만약 두 노드 모두 연결되어있지 않던 노드라면 bc, ac 모두 0이기 때문에 w가 저장된다.
		cost[ra] = bc - ac + w; 
	}

	int find(int a, int prev = -1) {
		if (tree[a] < 0) {
			return a;
		}
		tree[a] = find(tree[a], a);

		if (prev > 0) { // 이전 노드에 간선 비용 누적합
			cost[prev] += cost[a];
		}

		return tree[a];
	}

	~Disjoint_set() { delete[] tree; }
} DS;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n, m, a, b, w;
	char q;

	while(1) {
		cin >> n >> m;
		if (!n && !m) break;
		DS ds(n + 1);

		
		while(m--) {
			cin >> q >> a >> b;
			if (q == '!') {
				cin >> w;
				ds.merge(a, b, w);
			}
			else {
				if (ds.find(a) != ds.find(b)) {
					cout << "UNKNOWN" << endl;
				}
				else {
					cout << ds.cost[a] - ds.cost[b] << endl; // (r - a) - (r - b) = b - a
				}
			}
		}
	}
}