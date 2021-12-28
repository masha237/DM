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
 
vector<vector<int>> g;
vector<int> col;
int k;
 
int get_col(vector<int> &vector);
 
void dfs(int v, int c) {
    col[v] = c;
    for (int i : g[v]) {
        if (col[i])
            continue;
        dfs(i, get_col(g[i]));
    }
}
 
int get_col(vector<int> &a) {
    set<int> s;
    for (auto i : a) {
        s.insert(col[i]);
    }
    int m = 1;
    while (1) {
        if (s.find(m) == s.end())
            return m;
        m++;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> st(n);
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        st[x]++;
        st[y]++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    col.resize(n);
    k = *max_element(st.begin(), st.end());
    if (k % 2 == 0)
        k++;
    dfs(max_element(st.begin(), st.end()) - st.begin(), 1);
    cout << k << '\n';
    for (auto i : col)
        cout << i << '\n';
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
