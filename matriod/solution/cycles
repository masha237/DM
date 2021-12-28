#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int32_t main() {
    freopen("cycles.in", "r", stdin);
    freopen("cycles.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
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
    int sizeB = 0;
    vector<int> base;
    for (int i = 0; i < (1 << n); i++) {
        int sizeI = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sizeI++;
            }
            if (i & (1 << j) && ind[i ^ (1 << j)]) {
                ind[i] = 1;
            }
        }
        if (sizeI == sizeB && !ind[i]) {
            base.push_back(i);
        } else if (sizeI > sizeB && !ind[i]) {
            sizeB = sizeI;
            base = {i};
        }
    }
    int ans = 0;
    for (int i : base) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cur += w[j];
            }
        }
        ans = max(ans, cur);
    }
    cout << ans;
}
