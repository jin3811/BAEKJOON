/**
 * boj/10830
 * 
 * 빠른 행렬 제곱문제.
 * 빠른 제곱은 여러번 풀어본 방법이니 똑같이 적용하면 된다(지수를 반으로 나누는 분할정복).
 * 지수의 값이 int범위보다 크다(log_2(100000000000) = 36.5412090438). 지수의 자료형에 주의해야 한다.
 * 다음과 같은 케이스가 존재한다.
 * 2 1
 * 1000 1000
 * 1000 1000
 * 
 * 해당 케이스의 출력값은 다음과 같다.
 * 0 0
 * 0 0
 * 
 * 1000으로 나눈 나머지를 구해야하기 때문이다. 해당 케이스는 지수가 1이기 때문에 본인을 반환하고 끝나는데,
 * 이때 입력받을때 모듈러 처리를 하지 않는다면 1000으로 나눈 나머지를 출력하지 못한다.
 * 
 * 입력받을때 모듈러 처리를 거쳐야 한다.
 * 
 * 행렬곱셉의 구현 자체는 단순하지만, 캐시히트율을 올려 같은 시간복잡도를 가지더라도 더 빠르게 처리할수 있어야 한다. 반복문의 인덱스 순서르 조정하면 캐시히트율을 올릴 수 있다. https://sosal.kr/878
 */
#include <bits/stdc++.h>
#define ALL(X) X.begin(), X.end()
#define endl '\n'
using namespace std;
using ll = long long;

class Matrix2D {
	vector<vector<int>> mat;
	int row, col;
public:
	Matrix2D(int row = 0, int col = 0) {
		init(row, col);
	}

	void init(int row = 0, int col = 0) {
		this->row = row;
		this->col = col;
		this->mat.resize(row, vector<int>(col, 0));
	}

    Matrix2D& input() {
		for(auto& y : mat) {
			for(int& x : y) {
				cin >> x;
				x %= 1000;
			}
		}
		return *this;
    }

	Matrix2D operator*(const Matrix2D& other) {
		int r;
		Matrix2D tmp(this->row, other.col);

		for(int k = 0; k < this->col; k++) {
			for(int i = 0; i < this->row; i++) {
				r = mat[i][k];
				for(int j = 0; j < other.col; j++) {
					tmp.mat[i][j] += r * other.mat[k][j];
					tmp.mat[i][j] %= 1000;
				}
			}
		}

		return tmp;
	}

	vector<vector<int>> getData() { return mat; }

	void print() {
		for(auto& y : mat) {
			for(auto& x : y) cout << x << ' ';
			cout << endl;
		}
	}
	
	Matrix2D pow(ll a) {
		if (a == 1) return *this;

		Matrix2D tmp(pow(a / 2));

		if (a % 2 == 1) return (*this) * tmp * tmp;
		else return tmp * tmp;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n;
	ll b;

	cin >> n >> b;
	Matrix2D(n,n).input().pow(b).print();
}