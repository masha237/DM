#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;
 
vector<int> operator -(vector<int>& a, vector<int>& b) {
    vector<int> c(a.size());
    for (int i = 0; i < a.size(); i++) {
        c[i] = a[i] - (i < b.size() ? b[i] : 0);
    }
    return c;
}
 
vector<int> get(vector<vector<int>> g, vector<pair<int, int>> e, int n, int m) {
    if (m == 0) {
        vector<int> ans(n + 1);
        ans[n] = 1;
        return ans;
    }
    pair<int, int> kek = e.back();
    e.pop_back();
    g[kek.first][kek.second] = g[kek.second][kek.first] = 0;
    vector<int> a = get(g, e, n, m - 1);
    g[kek.first][kek.second] = g[kek.second][kek.first] = 1;
    e.push_back(kek);
 
    vector<int> ind(n);
    for (int i = 0; i < n; i++)
        ind[i] = i;
    swap(ind[kek.first], ind.back());
    ind[kek.first] = ind[kek.second];
    vector<vector<int>> g1(n - 1, vector<int>(n - 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (ind[i] != ind[j])
                g1[ind[i]][ind[j]] |= g[i][j];
        }
    vector<pair<int, int>> e1;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < i; j++)
            if (g1[i][j])
                e1.push_back({i, j});
    vector<int> b = get(g1, e1, n - 1, e1.size());
    return a - b;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    vector<vector<int>> g;
    int n, m;
    cin >> n >> m;
    g.resize(n, vector<int>(n));
    vector<pair<int, int>> e;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e.push_back({x, y});
        g[x][y] = g[y][x] = 1;
    }
 
    vector<int> ans = get(g, e, n, m);
    reverse(ans.begin(), ans.end());
    cout << n << '\n';
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}
 
/*
 5
 
0
10
111
0011
 
 5
 
0
10
000
1100
 
 
7
 
0
10
000
1100
01000
001101
 
 7
 
0
10
000
1100
11000
001101
 
  7
 
0
10
000
1100
11111
011111
 
 5
 0
 10
 000
 0010
 */
