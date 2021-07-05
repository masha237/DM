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

    freopen("problem4.in", "r", stdin);
    freopen("problem4.out", "w", stdout);

    int n, m, k, l;
    cin >> n >> m >> k >> l;
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
    int mod = 1e9 + 7;
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = 1;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            dp[(i + 1) % 2][j] = 0;
            for (auto q : gr[j]) {
                dp[(i + 1) % 2][j] += dp[i % 2][q.first];
                dp[(i + 1) % 2][j] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (t[i]) {
            ans = (ans + dp[l % 2][i]) % mod;
        }
    }
    cout << ans;
}