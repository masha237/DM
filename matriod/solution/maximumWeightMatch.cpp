#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<vector<ll>> g, g2;
vector<ll> mt, used;
vector<ll> r_p, l_p;
ll n, m, k;
 
bool dfs(ll v) {
    if (used[v]) return 0;
    used[v] = 1;
    for (auto i : g[v])
        if (mt[i] == -1) {
            mt[i] = v;
            return 1;
        }
    for (auto i : g[v])
        if (dfs(mt[i])) {
            mt[i] = v;
            return 1;
        }
    return 0;
}
 
int32_t main()
{
    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    g.resize(n);
    for (int i = 0; i < n; i++) {
        ll k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            ll x;
            cin >> x;
            x--;
            g[i].push_back(x);
        }
    }
    sort(a.rbegin(), a.rend());
    mt.assign(n, -1);
    for (int i = 0; i < n; i++) {
        used.assign(n, 0);
        dfs(a[i].second);
    }
    vector<ll> ans(n);
    for (int i = 0; i < n; i++)
        if (mt[i] != -1)
            ans[mt[i]] = i + 1;
    for (auto i : ans)
        cout << i << " ";
}
