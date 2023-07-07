#include <bits/stdc++.h>
#define endl '\n'
#define ALL(X) (X).begin(), (X).end()
using namespace std;

int a[3]; // a[n] = a_n
int c, n0;

void input() {
	for (int i = 2; i >= 0; --i) cin >> a[i];
	cin >> c >> n0;
}

int sol() {
    a[2] -= c;
	if (a[2] < 0) { // 위로 볼록. 무조건 안됨
		return 0;
	}
	else { // 일차 or 상수 or 아래로 볼록한 이차함수
        int m = 2 * a[2] * n0 + a[1];
        int D = a[1] * a[1] - 4 * a[2] * a[0];
        // if (D < 0) return 1;
        // else return (2 * a[2] * n0 + a[1] >= 0 &&
        //              a[2] * n0 * n0 + a[1] * n0 + a[0] >= 0);

        if (m < 0) return (-D / (4. * a[2])) >= 0;
        else return (a[2] * n0 * n0 + a[1] * n0 + a[0]) >= 0;
	}
}

int subsol1() {
    a[2] -= c;
	if (a[2] < 0) { // 위로 볼록. 무조건 안됨
		return 0;
	}
	else { // 일차 or 상수 or 아래로 볼록한 이차함수
        int m = 2 * a[2] * n0 + a[1];
        int D = a[1] * a[1] - 4 * a[2] * a[0];
        if (D < 0) return 1;
        else return (2 * a[2] * n0 + a[1] >= 0 &&
                     a[2] * n0 * n0 + a[1] * n0 + a[0] >= 0);
	}
}

int subsol2() {
    a[2] -= c;
	if (a[2] < 0) { // 위로 볼록. 무조건 안됨
		return 0;
	}
	else { // 일차 or 상수 or 아래로 볼록한 이차함수
        int m = 2 * a[2] * n0 + a[1];
        int D = a[1] * a[1] - 4 * a[2] * a[0];
        // if (D < 0) return 1;
        // else return (2 * a[2] * n0 + a[1] >= 0 &&
        //              a[2] * n0 * n0 + a[1] * n0 + a[0] >= 0);

        if (m < 0) return (-D / (4. * a[2])) >= 0;
        else return (a[2] * n0 * n0 + a[1] * n0 + a[0]) >= 0;
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// input();
	// cout << sol(); 

    for (a[2] = -100; a[2] <= 100; a[2]++) {
        for (a[1] = -100; a[1] <= 100; a[1]++) {
            for (a[0] = -100; a[0] <= 100; a[0]++) {
                for (c = 1; c <= 100; c++) {
                    for (n0 = 1; n0 <= 100; n0++) {
                        int wrong = subsol1();
                        a[2] += c;
                        int correct = subsol2();
                        a[2] += c;

                        if (correct != wrong) {
                            cout << a[2] << " " << a[1] << " " << a[0] << endl << c << endl << n0 << endl;
                            cout << "correct : " << correct << endl;
                            cout << "wrong   : " << wrong << endl; 
                            cout << "-----" << endl;
                        }
                    }
                }
            }
        }
    }
}