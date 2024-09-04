#include<bits/stdc++.h>
using namespace std;

int x1, x2;
int coef[3];

void input(){
    int b,c,d,e;
    cin>>x1>>x2>>coef[0]>>b>>c>>d>>e;
    coef[0] /= 3;
    coef[1] = (b-d)/2;
    coef[2] = c-e;
}

int F(int x){
    int res=0;
    for(int i=0; i<3; i++){
        res += coef[i];
        res *= x;
    }
    return res;
}

void sol(){
    cout << F(x2)-F(x1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    input();
    sol();
}