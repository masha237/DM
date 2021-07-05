#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> g1, g2;
vector<int> t1, t2, used1, used2;

int main() {


    freopen("equivalence.in", "r", stdin);
    freopen("equivalence.out", "w", stdout);


    int n1, m1, k1;
    cin >> n1 >> m1 >> k1;
    g1.resize(n1 + 1, vector<int> (26, -1));

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
        g1[x][c - 'a'] = y;
    }

    int n, m, k;
    cin >> n >> m >> k;
    g2.resize(n + 1, vector<int> (26, -1));
    used2.resize(n);
    t2.resize(n + 1);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        t2[x - 1] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        x--;
        y--;
        g2[x][c - 'a'] = y;
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<bool>> used(n1 + 1, vector<bool>(n + 1));
    used[0][0] = 1;
    while (!q.empty()) {
        int v = q.front().first;
        int u = q.front().second;
        q.pop();
        if (t1[v] != t2[u]) {
            cout << "NO";
            return 0;
        }
        for (int i = 0; i < 26; i++) {
            int tv = g1[v][i];
            int tu = g2[u][i];
            if (tv == -1)
                tv = n1;
            if (tu == -1)
                tu = n;
            if (!used[tv][tu]) {
                q.push({tv, tu});
                used[tv][tu] = 1;
            }
        }
    }
    cout << "YES";
}