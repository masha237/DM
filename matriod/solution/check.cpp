#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
bool check1(vector<int> ind) {
    return ind[0];
}
 
bool check2(vector<int> ind) {
    for (int i = 0; i < ind.size(); i++) {
        if (!ind[i]) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (i & (1 << j) && !ind[i & (1 << j)]) {
                return false;
            }
        }
    }
    return true;
}
 
bool check3(vector<int> ind) {
    vector<vector<int>> classSize(n + 1);
    for (int i = 0; i < (1 << n); i++) {
        if (ind[i]) {
            classSize[__builtin_popcount(i)].push_back(i);
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        if (!ind[i]) {
            continue;
        }
        vector<int> bit;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                bit.push_back(j);
            }
        }
        int clazz = __builtin_popcount(i);
        for (int j = 0; j < clazz; j++) {
            for (auto q : classSize[j]) {
                bool fl = false;
                for (auto b : bit) {
                    if (!(q & (1 << b)) && ind[q ^ (1 << b)]) {
                        fl = true;
                        break;
                    }
                }
                if (!fl) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
 
int32_t main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
 
    cin >> n >> k;
    vector<int> ind(1 << n);
    for (int i = 0; i < k; i++) {
        int l;
        cin >> l;
        int lel = 0;
        vector<int> kek(l);
        for (int j = 0; j < l; j++) {
            cin >> kek[j];
            kek[j]--;
            lel += (1 << kek[j]);
        }
        ind[lel] = 1;
    }
    if (check1(ind) && check2(ind) && check3(ind)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
 
}
