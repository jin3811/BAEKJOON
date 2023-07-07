#include <bits/stdc++.h>
using namespace std;

int m, n;
int st = -1, ed = 1e9;
vector<int> v;

void input()
{
    cin >> n >> m;
    v.resize(n);
    for (int &x : v)
    {
        cin >> x;
        st = max(x, st);
    }
}

bool check(int money)
{
    int hand = money;
    int cnt = 1;

    for (int x : v)
    {
        if (money < x)
            return false;

        if (hand >= x)
            hand -= x;
        else
        {
            cnt++;
            hand = money - x;
        }
    }
    return cnt <= m;
}

void sol()
{
    int mid;
    int result;
    while (st <= ed)
    {
        mid = (st + ed) / 2;

        if (check(mid))
        {
            ed = mid - 1;
            result = mid;
        }
        else
        {
            st = mid + 1;
        }
    }
    cout << result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    sol();
}