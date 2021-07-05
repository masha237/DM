#include <bits/stdc++.h>

using namespace std;
vector<int> cnt(26), used(26);
vector<vector<string>> g(26);
void dfs(int v) {
    used[v] = 1;
    for (auto i : g[v]) {
        for (auto j : i) {
            if (j >= 'a' && j <= 'z') {
                continue;
            }
            if (!used[j - 'A']) {
                dfs(j - 'A');
            }
        }
    }
}
int main() {
    freopen("automaton.in", "r", stdin);
    freopen("automaton.out", "w", stdout);
    int n;
    char ch;
    cin >> n >> ch;
    queue<char> q;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        string s;
        cin >> s;
        getline(cin, s);
        if (s.size()) {
            s.erase(s.begin());
        }
        g[c - 'A'].push_back(s);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        set<int> a, newa;
        a.insert(ch - 'A');
        bool fl = 0;
        for (int j = 0; j < s.size(); j++) {
            for (auto k : a) {
                for (auto kk : g[k]) {
                    if (kk[0] == s[j]) {
                        if (kk.size() == 2) {
                            newa.insert(kk[1] - 'A');
                        }
                        if (j == s.size() - 1 && kk.size() == 1) {
                            fl = 1;
                            break;
                        }
                    }
                }
            }
            a.clear();
            a.swap(newa);
        }
        if (fl) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
/*
100 N
C -> o
S -> rR
N -> p
C -> i
J -> lP
Y -> l
Q -> gB
K -> a
K -> j
J -> qK
Z -> z
A -> e
C -> s
W -> j
F -> w
U -> f
L -> g
I -> f
Z -> rO
O -> oP
F -> q
T -> lY
H -> u
R -> p
G -> pM
Q -> iK
U -> a
S -> k
S -> q
I -> kP
C -> kM
E -> kT
X -> wV
V -> cV
O -> eG
M -> kH
T -> uC
L -> hY
F -> sN
X -> g
X -> c
R -> rE
Z -> gE
W -> u
P -> rO
V -> nW
Y -> f
C -> p
V -> k
O -> p
A -> sD
T -> k
W -> u
Z -> mA
G -> k
H -> wI
K -> bW
Q -> gL
U -> z
A -> zK
O -> q
N -> j
B -> sV
H -> bL
N -> r
U -> xB
O -> kI
C -> iH
F -> hK
L -> vA
W -> t
P -> wU
X -> aI
Q -> uU
T -> jQ
U -> c
U -> w
X -> y
W -> l
D -> vV
T -> wN
I -> yQ
U -> b
J -> eP
T -> o
N -> h
Z -> hD
T -> d
F -> j
K -> hL
N -> f
J -> b
G -> b
Q -> eA
Z -> rL
E -> h
Z -> c
B -> fE
G -> mJ
B -> xQ
1
huenejgchnpqigolipajiiznbzp
 */