#include <bits/stdc++.h>

using namespace std;
vector<int> cnt(26), used(26);
vector<vector<string>> g(26);
void dfs(int v) {
    used[v] = 1;
    for (auto i : g[v]) {
        for (auto j : i) {
            if (j >= 'a' && j <= 'z') {
                continue;
            }
            if (!used[j - 'A']) {
                dfs(j - 'A');
            }
        }
    }
}
int main() {
    freopen("epsilon.in", "r", stdin);
    freopen("epsilon.out", "w", stdout);
    int n;
    char ch;
    cin >> n >> ch;
    queue<char> q;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        string s;
        cin >> s;
        getline(cin, s);
        if (s.size()) {
            s.erase(s.begin());
        }
        g[c - 'A'].push_back(s);
    }

    dfs(ch - 'A');
    vector<int> b = used;
    used.assign(26, 0);
    for (int i = 0; i < 26; i++) {
        for (auto j : g[i]) {
            if (j.empty()) {
                q.push(i + 'A');
                g[i].clear();
                used[i] = 1;
                cnt[i] = 1;
            }
        }
    }
    while (q.size()) {
        char c = q.front();
        q.pop();
        used[c - 'A'] = 1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i])
                continue;
            for (int k = 0; k < g[i].size(); k++) {
                bool fl = 1, kek = 0;
                for (auto j : g[i][k]) {
                    if (j >= 'a' && j <= 'z') {
                        fl = 0;
                        break;
                    } else {
                        if (used[j - 'A']) {
                            fl &= cnt[j - 'A'];
                        } else {
                            fl = 0;
                            kek = 1;
                        }
                    }
                }
                if (!kek) {
                    g[i][k].swap(g[i].back());
                    k--;
                    g[i].pop_back();
                }
                cnt[i] |= fl;
                if (fl) {
                    g[i].clear();
                    q.push(i + 'A');
                    break;
                }
            }
            if (!used[i] && g[i].size() == 0) {
                q.push(i + 'A');
            }
        }
    }

    for (int i = 'A'; i <= 'Z'; i++) {
        if (cnt[i - 'A'])
            cout << (char)i << ' ';
    }
    cout << endl;
    return 0;
}
/*
6 S
C ->
S -> AB
A -> B
A -> a
B ->
B -> b
 */