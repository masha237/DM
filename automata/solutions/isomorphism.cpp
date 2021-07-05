#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<pair<int, char>>> g1, g2;
vector<int> t1, t2, used1, used2;
void renum(int v1, int v2) {
    if (t1[v1] != t2[v2] || g1[v1].size() != g2[v2].size()) {
        cout << "NO";
        exit(0);
    }
    for (int i = 0; i < g1[v1].size(); i++) {
        if (g1[v1][i].second != g2[v2][i].second) {
            cout << "NO";
            exit(0);
        }
        int v = g1[v1][i].first, u = g2[v2][i].first;
        if (used1[v] != used2[u]) {
            cout << "NO";
            exit(0);
        }
        if (!used1[v]) {
            used1[v] = used2[u] = 1;
            renum(v, u);
        }
    }
}

bool cmp(pair<int, char> a, pair<int, char> b) {
    return a.second < b.second;
}
int main() {

    freopen("isomorphism.in", "r", stdin);
    freopen("isomorphism.out", "w", stdout);

    int n1, m1, k1;
    cin >> n1 >> m1 >> k1;
    g1.resize(n1);

    t1.resize(n1);
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
        g1[x].push_back({y, c});
    }

    int n, m, k;
    cin >> n >> m >> k;
    g2.resize(n);
    used2.resize(n);
    t2.resize(n);
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
        g2[x].push_back({y, c});
    }
    for (int i = 0; i < n1; i++)
        sort(g1[i].begin(), g1[i].end(), cmp);
    for (int i = 0; i < n; i++) {
        sort(g2[i].begin(), g2[i].end(), cmp);
    }
    vector<int> num1, num2;
    renum(0, 0);
    cout << "YES";
}