#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int S = 0, T = 0;
 
vector<int> pd, sz;
 
int get(int a) {
    if (a == -1) {
        return -1;
    }
    return pd[a] != a ? pd[a] = get(pd[a]) : a;
}
 
void dsu(int a, int b) {
    a = get(a);
    b = get(b);
    if (sz[a] > sz[b]) {
        swap(a, b);
    }
    pd[a] = b;
    sz[b] += sz[a];
}
 
void calcDSU() {
    pd.assign(n, 0);
    sz.assign(n, 1);
    for (int i = 0; i < n; i++) {
        pd[i] = i;
    }
}
 
struct ed {
    int x, y, c;
    ed() = default;
    ed(int x, int y, int c): x(x), y(y), c(c) {}
};
vector<ed> e;
vector<vector<int>> g;
void build (vector<int>&a) {
    S = m, T = m + 1;
    g.assign(m + 2, {});
    vector<int> s, t;
    vector<int> second(m);
    vector<int> col(101);
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        col[e[a[i]].c] = 1;
        cnt++;
        second[a[i]] = 1;
    }
    // graph
    for (int i = 0; i < m; i++) {
        if (!second[i]) {
            continue;
        }
        calcDSU();
        for (int j = 0; j < m; j++) {
            if (second[j] && i != j) {
                dsu(e[j].x, e[j].y);
            }
        }
        for (int j = 0; j < m; j++) {
            if (!second[j]) {
                if (get(e[j].x) != get(e[j].y)) {
                    g[i].push_back(j);
                }
            }
        }
    }
    calcDSU();
    for (int j = 0; j < m; j++) {
        if (second[j]) {
            dsu(e[j].x, e[j].y);
        }
    }
    for (int j = 0; j < m; j++) {
        if (!second[j]) {
            if (get(e[j].x) != get(e[j].y)) {
                s.push_back(j);
            }
        }
    }
    // color
    for (int i = 0; i < m; i++) {
        if (second[i]) {
            col[e[i].c] = 0;
            for (int j = 0; j < m; j++) {
                if (!second[j] && !col[e[j].c]) {
                    g[j].push_back(i);
                }
            }
            col[e[i].c] = 1;
        }
    }
    for (int j = 0; j < m; j++) {
        if (!second[j] && !col[e[j].c]) {
            t.push_back(j);
        }
    }
    // add ST
    for (int i : s) {
        g[S].push_back(i);
    }
    for (int i : t) {
        g[i].push_back(T);
    }
}
 
vector<int> getPath() {
    queue<int> q;
    q.push(S);
    vector<int> d(g.size(), -1), p(g.size(),-1);
    d[S] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto i : g[v]) {
            if (d[i] == -1) {
                d[i] = d[v] + 1;
                p[i] = v;
                q.push(i);
            }
        }
    }
    if (d[T] == -1) {
        return {};
    }
    vector<int> path;
    while (T != -1) {
        path.push_back(T);
        T = p[T];
    }
    return path;
}
 
int32_t main() {
    freopen("rainbow.in", "r", stdin);
    freopen("rainbow.out", "w", stdout);
 
    cin >> n >> m;
    e.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].x >> e[i].y >> e[i].c;
        e[i].x--;
        e[i].y--;
    }
    vector<int> ans;
    bool isMax = 0;
    while (!isMax) {
        build(ans);
        vector<int> p = getPath();
        if (p.empty()) {
            isMax = true;
        } else {
            vector<int> kek(m);
            for (int i = 0; i < ans.size(); i++) {
                kek[ans[i]]++;
            }
            for (int i : p) {
                if (i < m)
                    kek[i] ^= 1;
            }
            ans.clear();
            for (int i = 0; i < m; i++) {
                if (kek[i]) {
                    ans.push_back(i);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i + 1 << ' ';
    }
}
