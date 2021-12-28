#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
int main() {
    vector<int> ans = {1};
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int l = -1, r = i - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            cout << "1 " << ans[m] << ' ' << i << endl;
            string s;
            cin >> s;
            if (s == "NO") {
                r = m;
            } else {
                l = m;
            }
        }
        ans.insert(ans.begin() + l + 1, i);
    }
    for (int i = 0; i < n - 1; i++) {
        cout << "1 " << ans[i] << ' ' << ans[i + 1] << endl;
        string s;
        cin >> s;
        if (s == "NO") {
            for (int i = 0; i < n + 1; i++)
                cout << "0 ";
            cout << endl;
            return 0;
        }
    }
    cout << "0 ";
 
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
