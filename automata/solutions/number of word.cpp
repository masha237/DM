#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> used, ord;
bool findC(int v, vector<vector<pair<int, char>>>& g) {
    used[v] = 1;
    for (auto i : g[v]) {
        if (used[i.first] == 1) {
            return true;
        } else if (used[i.first] == 0) {
            if (findC(i.first, g))
                return true;
        }
    }

    used[v] = 2;
    ord.push_back(v);
    return false;
}


int main() {

    freopen("problem3.in", "r", stdin);
    freopen("problem3.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, char>>> g(n), gr(n);
    vector<int> t(n);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        t[x - 1] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x--;
        y--;
        g[x].push_back({y, c});
        gr[y].push_back({x, c});
    }
    queue<int> q;
    q.push(0);
    vector<int> d(n), d2(n);
    d[0] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto i : g[v]) {
            if (!d[i.first]) {
                d[i.first] = 1;
                q.push(i.first);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (t[i]) {
            d2[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto i : gr[v]) {
            if (!d2[i.first]) {
                d2[i.first] = 1;
                q.push(i.first);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i] + d2[i] != 2)
            g[i].clear();
        for (int j = 0; j < g[i].size(); j++) {
            if (d[g[i][j].first] + d2[g[i][j].first] != 2) {
                g[i][j].swap(g[i].back());
                g[i].pop_back();
            }
        }
    }
    used.resize(n);
    int mod = 1e9 + 7;
    if (findC(0, g)) {
        cout << -1;
        return 0;
    } else {
        reverse(ord.begin(), ord.end());
        vector<int> dp(n);
        dp[0] = 1;
        for (auto i : ord) {
            for (auto j : gr[i]) {
                dp[i] += dp[j.first];
                dp[i] %= mod;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (t[i]) {
                ans = (ans + dp[i]) % mod;
            }
        }
        cout << ans;
    }
}