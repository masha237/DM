#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<int> p, sz;
 
int get(int a) {
    return p[a] != a ? p[a] = get(p[a]) : a;
}
 
void dsu(int a, int b) {
    a = get(a);
    b = get(b);
    if (sz[a] > sz[b]) {
        swap(a, b);
    }
    p[a] = b;
    sz[b] += sz[a];
}
 
int32_t main()
{
    freopen("destroy.in", "r", stdin);
    freopen("destroy.out", "w", stdout);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<pair<ll, int>, pair<int, int>>> e;
    vector<int> used(m);
    p.resize(n);
    sz.resize(n, 1);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        ll x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        e.push_back({{c, i}, {x, y}});
    }
    sort(e.rbegin(), e.rend());
    for (int i = 0; i < m; i++) {
        if (get(e[i].second.first) != get(e[i].second.second)) {
            dsu(e[i].second.first, e[i].second.second);
            used[i] = 1;
        }
    }
    vector<int> ans;
    for (int i = m - 1; i >= 0; i--) {
        if (!used[i]) {
            if (k >= e[i].first.first) {
                k -= e[i].first.first;
                ans.push_back(e[i].first.second + 1);
            } else {
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i << ' ';
    }
}
