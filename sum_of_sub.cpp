#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)

ll n, c, m;
vector<ll> a;

void sub(ll s, ll i, vector<ll> &v)
{
    if (s == m)
    {
        c++;
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    if (s > m || i >= n)
        return;
    v.push_back(a[i]);
    sub(s + a[i], i + 1, v);
    v.pop_back();
    sub(s, i + 1, v);
}

int main()
{
    FAST;
    ll i, j;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> j;
        a.push_back(j);
    }

    cin >> m;
    vector<ll> v;
    sub(0, 0, v);

    cout << c << endl;

    return 0;
}