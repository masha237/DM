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
    deque<int> q;
    for (int i = 0; i < n; i++)
        q.push_back(i);
    for (int k = 0; k <= n * (n - 1); k++) {
        int v = q[0], u = q[1];
        int i = 0;
        if (g[v][u] == 0) {
            i = 2;
        } else {
            q.push_back(q.front());
            q.pop_front();
            continue;
        }
        while (!g[q[0]][q[i]] || !g[q[1]][q[i + 1]]) {
            i++;
        }
        swap(q[i], q[1]);
 
        q.push_back(q.front());
        q.pop_front();
 
    }
 
    for (int i = 0; i < n; i++)
        cout << q[i] + 1 << ' ';
    return 0;
}
