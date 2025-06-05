#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <cmath>
#include <map>
#include <set>

using namespace std;
#define inout std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAXL = 1e18, MAX = 1e9;
const ll INV2 = 500000004;


void solve() {
    string s, l, r;
    int m;
    cin >> s >> m >> l >> r;

    int frontl = 0, frontr = 0;
    for (int i = 0; i < s.size(); i++) {
        char e = s[i];

        if (e == l[frontl] && frontl < m) {
            frontl++;
        }

        if (e == r[frontr] && frontr < m) {
            frontr++; 
        }
    }

    if (frontl == m && frontr == m) {
        cout << "NO\n"; 
    } else {
        cout << "YES\n";
    }
}

int main() {
    inout;
    int t = 1;
    std::cin >> t;
    
    while (t--) solve();
}
