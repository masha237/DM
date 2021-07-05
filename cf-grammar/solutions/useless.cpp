#include <bits/stdc++.h>

using namespace std;
vector<int> cnt(26), used(26);
vector<vector<string>> g(26);
void dfs(int v) {
    used[v] = 1;
    for (auto i : g[v]) {
        bool all = 1;
        for (auto j : i) {
            if (j >= 'a' && j <= 'z') {
                continue;
            }
            if (!cnt[j - 'A']) {
                all = 0;
            }
        }
        if (all) {
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
}
int main() {
    freopen("useless.in", "r", stdin);
    freopen("useless.out", "w", stdout);
    int n;
    char ch;
    cin >> n >> ch;
    set<char> se;
    se.insert(ch);
    queue<char> q;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        string s;
        cin >> s;
        getline(cin, s);
        se.insert(c);
        if (s.size()) {
            s.erase(s.begin());
        }
        g[c - 'A'].push_back(s);
        bool fl = 0;
        for (auto i : s) {
            if (i >= 'A' && i <= 'Z') {
                fl = 1;
                se.insert(i);
            }
        }
        if (!fl) {
            cnt[c - 'A'] = 1;
            q.push(c);
        }
    }
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        used[c - 'A'] = 1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i])
                continue;
            for (auto &k : g[i]) {
                bool fl = 1;
                for (auto j : k) {
                    if (j >= 'a' && j <= 'z') {
                    } else {
                        if (used[j - 'A']) {
                            fl &= cnt[j - 'A'];
                        } else {
                            fl = 0;
                        }
                    }
                }
                cnt[i] |= fl;
                if (fl) {
                    q.push(i + 'A');
                    break;
                }
            }
        }
    }
    used.assign(26, 0);
    if (cnt[ch - 'A'])
        dfs(ch - 'A');
    vector<int> b = used;
    for (int i = 'A'; i <= 'Z'; i++) {
        if (!(cnt[i - 'A'] & b[i - 'A']) && se.find(i) != se.end())
            cout << (char) i << ' ';
    }
    cout << endl;
    return 0;
}
/*
3 A
A -> q
A -> BC
B -> q
 */