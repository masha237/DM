#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> st(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        st[x]++;
        st[y]++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        if (st[i] == 1) {
            q.push(-i);
        }
    }
    int ind = 0;
    while (ind != n - 2) {
        ind++;
        int v = -q.top();
        st[v]--;
        q.pop();
        for (auto i : g[v]) {
            if (st[i]) {
                cout << i + 1 << ' ';
                st[i]--;
            }
            if (st[i] == 1) {
                q.push(-i);
            }
        }
    }
    return 0;
}
