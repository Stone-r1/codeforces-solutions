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
    ll n, k, x, count = 0;
    cin >> n >> k;

    unordered_map<ll, ll> a, b;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!(x % k)) {
            count += b[x / k];
            b[x] += a[x / k];
        } 
        a[x]++;
    }

    cout << count << '\n';
}

int main() {
    inout;
    int t = 1;
    // std::cin >> t;
    
    while (t--) solve();
}
