// #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
/*
*
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 
*/
 
std::mt19937 rnd(238);
#define VERSION "0.1.5"
 
#include <cassert>
#include <cstdio>
#include <algorithm>
 
 
#ifdef FAST_ALLOCATOR_MEMORY
int allocator_pos = 0;
    char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
    inline void * operator new ( size_t n ) {
        char *res = allocator_memory + allocator_pos;
        allocator_pos += n;
        assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
        return (void *)res;
    }
    inline void operator delete ( void * ) noexcept { }
    //inline void * operator new [] ( size_t ) { assert(0); }
    //inline void operator delete [] ( void * ) { assert(0); }
#endif
using namespace std;
typedef long long ll;
int n, m;
int S = 0, T = 0;
 
vector<vector<int>> pd, sz;
 
int get(int a, int l) {
    if (a == -1) {
        return -1;
    }
    return pd[l][a] != a ? pd[l][a] = get(pd[l][a], l) : a;
}
 
void dsu(int a, int b, int l) {
    a = get(a, l);
    b = get(b, l);
    if (sz[l][a] > sz[l][b]) {
        swap(a, b);
    }
    pd[l][a] = b;
    sz[l][b] += sz[l][a];
}
 
void calcDSU(int N) {
    pd.assign(N, vector<int>(n));
    sz.assign(N, vector<int>(n, 1));
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < n; i++) {
            pd[j][i] = i;
        }
    }
}
 
struct ed {
    int x, y, ind;
    ed() = default;
    ed(int x, int y, int ind): x(x), y(y), ind(ind) {}
};
ed e[2005];
int used1[2005];
vector<vector<int>> g;
vector<bitset<2005>> used;
int step[2005];
void build (int N) {
    S = m, T = m + 1;
    g.assign(m + 2, {});
    vector<int> s;
    memset(step, -1,sizeof(step));
    for (int k = 0; k < N; k++) {
        for (auto i = used[k]._Find_first(); i != used[k].size(); i = used[k]._Find_next(i)) {
            calcDSU(1);
            for (auto j = used[k]._Find_first(); j != used[k].size(); j = used[k]._Find_next(j)) {
                if (i != j) {
                    dsu(e[j].x, e[j].y, 0);
                }
            }
            for (int j = 0; j < m; j++) {
                if (!used[k][j]) {
                    if (get(e[j].x, 0) != get(e[j].y, 0)) {
                        g[i].push_back(j);
                    }
                }
            }
        }
        calcDSU(1);
        for (auto i = used[k]._Find_first(); i != used[k].size(); i = used[k]._Find_next(i)) {
            dsu(e[i].x, e[i].y, 0);
        }
 
        for (int j = 0; j < m; j++) {
            if (!used[k][j]) {
                if (get(e[j].x, 0) != get(e[j].y, 0)) {
                    s.push_back(j);
                    step[j] = k;
                }
            }
        }
    }
    for (int i : s) {
        g[S].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        if (used1[i] == -1) {
            g[i].push_back(T);
        }
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
    reverse(path.begin(), path.end());
    return path;
}
 
void greedy(int cnt) {
    calcDSU(cnt);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < cnt; j++) {
            if (get(e[i].x, j) != get(e[i].y, j)) {
                dsu(e[i].x, e[i].y, j);
                used[j][i] = true;
                used1[i] = j;
                break;
            }
        }
    }
    return;
}
 
vector<int> intersect(int cnt) {
    memset(used1, -1,sizeof(used1));
    vector<bitset<2005>> lel(cnt);
    used.swap(lel);
    greedy(cnt);
    bool isMax = false;
    while (!isMax) {
        build(cnt);
        vector<int> p = getPath();
        if (p.empty()) {
            isMax = true;
        } else {
            for (int i = 1; i < p.size() - 2; i++) {
                int from = p[i];
                int to = p[i + 1];
                int st = used1[from];
                used[st][from] = !used[st][from];
                used[st][to] = !used[st][to];
            }
            memset(used1, -1,sizeof(used1));
            for (int i = 0; i < cnt; i++) {
                if (i == step[p[1]]) {
                    used[i][p[1]] = 1;
                }
                for (auto j = used[i]._Find_first(); j != used[i].size(); j = used[i]._Find_next(j)) {
                    used1[j] = i;
                }
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < cnt; i++) {
        for (auto j = used[i]._Find_first(); j != used[i].size(); j = used[i]._Find_next(j)) {
            ans.push_back(e[j].ind + i * m);
        }
    }
    return ans;
}
 
int32_t main() {
    freopen("multispan.in", "r", stdin);
    freopen("multispan.out", "w", stdout);
 
    cin >> n >> m;
    vector<int> st(n);
    for (int i = 0; i < m; i++) {
        cin >> e[i].x >> e[i].y;
        e[i].x--;
        e[i].y--;
        e[i].ind = i;
        st[e[i].x]++;
        st[e[i].y]++;
    }
    shuffle(e, e + m, rnd);
    int l = 0, r = 2001;
    for (int i = 0; i < n; i++) {
        r = min(r, (int)st[i] + 1);
    }
 
    while (r - l > 1) {
        int M = (r + l) / 2;
        vector<int> kek = intersect(M);
        if (kek.size() == M * (n - 1)) {
            l = M;
        } else {
            r = M;
        }
    }
    vector<int> ans = intersect(l);
    cout << l << endl;
    vector<vector<int>> kek(l);
    for (int i : ans) {
        kek[i / m].push_back(i % m + 1);
    }
    for (auto i : kek) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}
