#include <bits/stdc++.h>

using namespace std;
vector<int> cnt(26), used(26);
vector<vector<string>> g(26);
vector<vector<char>> cc(26);
typedef long long ll;
int main() {
    freopen("nfc.in", "r", stdin);
    freopen("nfc.out", "w", stdout);

    int n;
    char ch;
    cin >> n >> ch;
    set<char> se;
    se.insert(ch);
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
        if (s.size() == 1) {
            cc[c - 'A'].push_back(s[0]);
        } else {
            g[c - 'A'].push_back(s);
        }
    }
    string s;
    while (cin >> s) {
        vector<vector<vector<ll>>> dp(26, vector<vector<ll>>(s.size(), vector<ll>(s.size())));
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 26; j++) {
                for (auto k : cc[j]) {
                    dp[j][i][i] += (s[i] == k);
                }
            }
        }
        ll mod = 1e9 + 7;
        for (int i = 2; i <= s.size(); i++) {
            for (int l = 0; l < s.size(); l++) {
                int r = l + i - 1;
                if (r >= s.size())
                    break;
                for (int c = 0; c < 26; c++) {
                    for (int m = l; m < r; m++) {
                        for (auto e : g[c]) {
                            dp[c][l][r] += dp[e[0] - 'A'][l][m] * dp[e[1] - 'A'][m + 1][r];
                            dp[c][l][r] %= mod;
                        }
                    }
                }
            }
        }
        cout << dp[ch - 'A'][0][s.size() - 1] << endl;
    }
    return 0;
}
/*
3 A
A -> q
A -> BC
B -> q
 */