include <bits/stdc++.h>
using namespace std;
mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            char x;
            cin >> x;
            g[i][j] = g[j][i] = x - '0';
        }
    }
 
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i] += g[i][j];
        }
    }
    int m = 2;
    vector<pair<int, int>> add;
    while (1) {
        bool fl = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (d[i] + d[j] >= n && g[i][j] == 0) {
                    fl = 1;
                    add.push_back({i, j});
                    g[i][j] = g[j][i] = m;
                    m++;
                    d[i]++;
                    d[j]++;
                }
            }
        }
        if (!fl) {
            break;
        }
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        c[i] = i;
    for (int i = add.size() - 1; i >= 0; i--) {
        g[add[i].first][add[i].second] = g[add[i].second][add[i].first] = 0;
        int j = 0;
        c.push_back(c[0]);
        for (; j < n; j++) {
            if (!g[c[j]][c[j + 1]])
                break;
        }
        if (j != n) {
            c.pop_back();
            vector<int> c2 = c;
            for (int k = j + 1; k < n; k++)
                c[k - j - 1] = c2[k];
            for (int k = 0; k <= j; k++)
                c[k + (n - j - 1)] = c2[k];
            int l = 0;
            for (int k = 0; k < n - 1; k++) {
                if (g[c[0]][c[k + 1]] && g[c[k]][c[n - 1]]) {
                    l = k;
                    break;
                }
            }
            c2 = c;
            c.clear();
            c.push_back(c2[0]);
            for (int k = l + 1; k < n; k++) {
                c.push_back(c2[k]);
            }
            for (int k = l; k > 0; k--)
                c.push_back(c2[k]);
        } else {
            c.pop_back();
        }
    }
    for (auto i : c)
        cout << i + 1 << ' ';
}
