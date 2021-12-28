#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> st(n, 1);
    vector<int> code(n - 2);
    for (int i = 0; i < n - 2; i++) {
        cin >> code[i];
        code[i]--;
        st[code[i]]++;
    }
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        if (st[i] == 1) {
            q.push(-i);
        }
    }
    for (int i = 0; i < n - 2; i++) {
        st[code[i]]--;
        int v = -q.top();
        q.pop();
        st[v]--;
        cout << v + 1 << ' ' << code[i] + 1 << '\n';
        if (st[code[i]] == 1) {
            q.push(-code[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (st[i] == 1)
            cout << i + 1 << ' ';
    }
    return 0;
}
