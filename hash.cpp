#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, b;
    cin >> s >> b;
    ll k, i, j;
    cin >> k;
    set<pair<ll, ll>> st;

    for (i = 0; i < s.size(); i++)
    {
        ll bc = 0, h1 = 0, h2 = 0, p1 = 1, p2 = 1, b1 = 31, b2 = 29, MOD = 1e9 + 7;
        for (j = i; j < s.size(); j++)
        {
            bc += (b[s[j] - 'a'] == '0' ? 1 : 0);
            if (bc > k)
                break;
            h1 += ((s[j] - 'a' + 1) * p1) % MOD;
            h2 += ((s[j] - 'a' + 1) * p2) % MOD;
            p1 = (p1 * b1) % MOD;
            p2 = (p2 * b2) % MOD;
            st.insert({h1, h2});
        }
    }
    cout << st.size() << endl;
    return 0;
}

vector<int> rabinKarp(string const &pattern, string const &text)
{
    const int p = 31;
    const int m = 1e9 + 9;
    int S = pattern.size(), T = text.size();

    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i + 1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % m;

    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (pattern[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++)
    {
        long long cur_h = (h[i + S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}