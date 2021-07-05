#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    freopen("problem2.in", "r", stdin);
    freopen("problem2.out", "w", stdout);


    string s;
    getline(cin, s);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, char>>> g(n);
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
    }

    queue<pair<int, int>> q;
    vector<int> used(n);
    q.push({0, 0});
    while (!q.empty()) {
        int l, v;
        l = q.front().second;
        v = q.front().first;
        q.pop();
        if (l == s.size()) {
            if (t[v]) {
                cout << "Accepts";
                return 0;
            }
            continue;
        }
        for (auto i : g[v]) {
            if (i.second == s[l] && used[i.first] != l + 1) {
                used[i.first] = l + 1;
                q.push({i.first, l + 1});
            }
        }
    }
    cout << "Rejects";
}