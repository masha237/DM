#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {



    freopen("minimization.in", "r", stdin);
    freopen("minimization.out", "w", stdout);




    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, char>>> g(n), grr(n);
    vector<vector<vector<int>>> gr(n, vector<vector<int>>(26));
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
        grr[y].push_back({x, c});
        gr[y][c - 'a'].push_back(x);
    }
    queue<int> qq;
    qq.push(0);
    vector<int> d(n), d2(n);
    d[0] = 1;
    while (!qq.empty()) {
        int v = qq.front();
        qq.pop();
        for (auto i : g[v]) {
            if (!d[i.first]) {
                d[i.first] = 1;
                qq.push(i.first);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (t[i]) {
            d2[i] = 1;
            qq.push(i);
        }
    }
    while (!qq.empty()) {
        int v = qq.front();
        qq.pop();
        for (auto i : grr[v]) {
            if (!d2[i.first]) {
                d2[i.first] = 1;
                qq.push(i.first);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i] + d2[i] != 2)
            g[i].clear();
        for (int j = 0; j < g[i].size(); j++) {
            if (d[g[i][j].first] + d2[g[i][j].first] != 2) {
                g[i][j].swap(g[i].back());
                j--;
                g[i].pop_back();
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto j : g[i]) {
            gr[j.first][j.second - 'a'].push_back(i);
        }
    }

    vector<int> clas(n);

    queue<pair<int, int>> q;
    vector<unordered_set<int>> p(2);
    for (int i = 0; i < n; i++) {
        if (d[i] + d2[i] != 2)
            continue;
        p[t[i]].insert(i);
        clas[i] = t[i];
    }

    for (int cc = 0; cc < 26; cc++) {
        q.push({1, cc});
        q.push({0, cc});
    }
    while (!q.empty()) {
        int ind = q.front().first;
        int ch = q.front().second;
        q.pop();
        map<int, set<int>> inv;
        for (auto i : p[ind]) {
            for (auto kk : gr[i][ch]) {
                int qq = clas[kk];
                inv[qq].insert(kk);
            }
        }
        for (auto i : inv) {
            if (inv[i.first].size() < p[i.first].size()) {
                p.push_back({});
                int j = p.size() - 1;
                for (auto qq : inv[i.first]) {
                    p[j].insert(qq);
                    p[i.first].erase(qq);
                }
                if (p[i.first].size() < p[j].size()) {
                    p[i.first].swap(p[j]);
                }
                for (auto qq : p[j]) {
                    clas[qq] = j;
                }
                for (int cc = 0; cc < 26; cc++) {
                    q.push({j, cc});
                }
            }
        }
    }
    map<int, int> mp;

    int c = clas[0];
    for (int i = 0; i < n; i++) {
        if (d[i] + d2[i] != 2)
            clas[i] = 0;
        else if (clas[i] == c)
            clas[i] = 0;
        else if (clas[i] == 0) {
            clas[i] = c;
        }
    }
    vector<int> kek = clas;
    sort(kek.begin(), kek.end());

    for (auto i : kek) {
        if (mp.find(i) == mp.end()) {
            mp[i] = mp.size();
        }
    }
    set<int> lol;
    for (int i = 0; i < n; i++) {
        clas[i] = mp[clas[i]];
        if (d[i] + d2[i] == 2 && t[i])
            lol.insert(clas[i]);
    }
    set<pair<pair<int, int>, char>> ans;
    for (auto &i : p) {
        for (auto v : i) {
            for (auto j : g[v]) {
                ans.insert({{clas[v], clas[j.first]}, j.second});
            }
        }
    }
    cout << mp.size() << " " << ans.size() << ' ' << lol.size() << endl;
    for (auto i : lol) {
        cout << i + 1 << ' ';
    }
    cout << endl;
    for (auto i : ans) {
        cout << i.first.first + 1 << ' ' << i.first.second + 1 << ' ' << i.second << endl;
    }
}