#include <bits/stdc++.h>

using namespace std;
vector<vector<string>> g(52), gg;
vector<vector<vector<int>>> g1(52);
vector<vector<char>> cc(52);
typedef long long ll;

vector<int> clas(256);
int get(int v) {
    return clas[v] == v ? v : clas[v] = get(clas[v]);
}
void dsu(int a, int b) {
    a = get(a);
    b = get(b);
    if (rand() % 2) {
        swap(a, b);
    }
    clas[a] = b;
}
int main() {
    freopen("cf.in", "r", stdin);
    freopen("cf.out", "w", stdout);

    int n;
    char ch;
    cin >> n >> ch;
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
    gg = g;
    queue<char> q;
    vector<int> used, cnt(256);
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
    g = gg;

    for (int c = 0; c <= 255; c++)
        clas[c] = c;
    for (int i = 0; i < 26; i++)
        for (auto s : g[i]) {
            if (s.size()) {
                if (s.size() == 1 && s[0] <= 'z' && s[0] >= 'a') {
                    cc[i].push_back(s[0]);
                    continue;
                }
                vector<int> buf;
                for (int j = 0; j < s.size(); j++) {
                    if (s[j] <= 'z' && s[j] >= 'a') {
                        buf.push_back(26 + (s[j] - 'a'));
                        cc[26 + (s[j] - 'a')].push_back(s[j]);
                    } else {
                        buf.push_back(s[j] - 'A');
                    }
                }
                if (buf.size() == 2) {
                    g1[i].push_back(buf);
                    continue;
                }
                if (buf.size() == 1) {
                    dsu(i, buf[0]);
                    continue;
                }
                int ind = i;
                for (int i = 1; i < buf.size(); i++) {
                    vector<int> s;
                    s.push_back(buf[i - 1]);
                    if (i != buf.size() - 1) {
                        s.push_back(g1.size());
                        g1.push_back({});
                        cc.push_back({});
                    } else
                        s.push_back(buf[i]);
                    g1[ind].push_back(s);
                    ind = s[1];
                }
            }
        }
    for (int i = 0; i < g1.size(); i++) {
        int sz = g1[i].size();
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < g1[i][j].size(); k++) {
                if (cnt[g1[i][j][k]]) {
                    dsu(i, g1[i][j][k ^ 1]);
                    continue;
                }
            }
        }
    }
    for (int i = 0; i < g1.size(); i++) {
        int x = get(i);
        if (x != i) {
            for (auto j : g1[i]) {
                g1[x].push_back(j);
            }
            for (auto j : cc[i]) {
                cc[x].push_back(j);
            }
        }
    }
    for (int i = 0; i < g1.size(); i++) {
        for (int j = 0; j < g1[i].size(); j++) {
            for (int k = 0; k < g1[i][j].size(); k++) {
                g1[i][j][k] = get(g1[i][j][k]);
            }
        }
    }
    string s;
    cin >> s;
    vector<vector<vector<ll>>> dp(g1.size(), vector<vector<ll>>(s.size(), vector<ll>(s.size())));
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < g1.size(); j++) {
            for (auto k : cc[j]) {
                dp[j][i][i] |= (s[i] == k);
            }
        }
    }
    for (int i = 2; i <= s.size(); i++) {
        for (int l = 0; l < s.size(); l++) {
            int r = l + i - 1;
            if (r >= s.size())
                break;
            for (int c = 0; c < g1.size(); c++) {
                for (int m = l; m < r; m++) {
                    for (auto e : g1[c]) {
                        if (dp[e[0]][l][m] * dp[e[1]][m + 1][r]) {
                            dp[c][l][r] |= dp[e[0]][l][m] * dp[e[1]][m + 1][r];
                        }
                    }
                }
            }
        }
    }
    cout << (dp[get(ch - 'A')][0][s.size() - 1] ? "yes" : "no");
    return 0;
}
/*
3 A
A -> q
A -> BC
B -> q
 */