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
    int n, m, x, count = 1;
    cin >> n >> m;

    unordered_map<int, int> freq, amount;
    for (int i = 0; i < m; i++) {
        cin >> x;
        freq[x]++;
        amount[freq[x]]++;
        if (amount[count] == n) {
            cout << "1";
            count++;
        } else {
            cout << "0";
        }
    }
}

int main() {
    inout;
    int t = 1;
    // std::cin >> t;
    
    while (t--) solve();
}
