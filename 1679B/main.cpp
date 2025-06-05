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
    ll n, q;
    cin >> n >> q;
    
    ll sum = 0;
    ll arr[n], lastUpdate[n] = {-1};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        lastUpdate[i] = 0;
    }
    
    ll lastChange = -1, last = 0, now = 0;
    while (q--) {
        int op;
        cin >> op;
        now++;
        
        if (op == 1) {
            ll idx, x, old;
            cin >> idx >> x; idx--;
            
            if (last > lastUpdate[idx]) {
                old = lastChange;
            } else {
                old = arr[idx];
            }
            
            sum = sum - old + x;
            arr[idx] = x;
            lastUpdate[idx] = now;
        } else {
            int x;
            cin >> x;
            sum = 1LL * n * x;
            lastChange = x;
            last = now;
        }
        
        cout << sum << '\n';
    }
}

int main() {
    inout;
    int t = 1;
    // std::cin >> t;
    
    while (t--) solve();
}
