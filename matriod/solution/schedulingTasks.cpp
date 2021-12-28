#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int32_t main() {
    freopen("schedule.in", "r", stdin);
    freopen("schedule.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    set<int> time;
    for (int i = 0; i < n; i++) {
        time.insert(i);
        cin >> a[i].second >> a[i].first;
    }
    sort(a.rbegin(), a.rend());
    ll t = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        auto ind = time.lower_bound(a[i].second);
        if (ind == time.begin()) {
            ans += a[i].first;
        } else {
            ind--;
            time.erase(ind);
        }
    }
    cout << ans;
}
