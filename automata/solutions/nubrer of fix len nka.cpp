#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<vector<int>>> g1;
vector<vector<int>> gr;
vector<int> t1, t2, used1, used2;

int main() {


    freopen("problem5.in", "r", stdin);
    freopen("problem5.out", "w", stdout);



    int n1, m1, k1, l;
    cin >> n1 >> m1 >> k1 >> l;
    g1.resize(n1 + 1, vector<vector<int>> (26));

    t1.resize(n1 + 1);
    used1.resize(n1);

    for (int i = 0; i < k1; i++) {
        int x;
        cin >> x;
        t1[x - 1] = 1;
    }
    for (int i = 0; i < m1; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x--;
        y--;
        g1[x][c - 'a'].push_back(y);
    }

    queue<set<int>> q;
    map<set<int>, int> was;
    was[{0}] = 0;
    q.push({0});
    gr.emplace_back();
    vector<int> t(1);
    if (t1[0])
        t.back() = 1;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        for (int i = 0; i < 26; i++) {
            set<int> u;
            bool fl = 0;
            for (auto j : v) {
                for (auto j1 : g1[j][i]) {
                    u.insert(j1);
                    fl |= t1[j1];
                }
            }
            if (was.find(u) == was.end()) {
                was[u] = (int)was.size();
                t.push_back(fl);
                gr.emplace_back();
                gr[was[u]].push_back(was[v]);
                q.push(u);
            } else {
                gr[was[u]].push_back(was[v]);
            }
        }
    }
    int n = was.size();
    int mod = 1e9 + 7;
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = 1;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            dp[(i + 1) % 2][j] = 0;
            for (auto q : gr[j]) {
                dp[(i + 1) % 2][j] += dp[i % 2][q];
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