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
    int n;
    cin >> n;

    int arr[n];
    map<ll, ll> freq;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    ll count = 0;
    for (auto& [x, amount] : freq) { 
        for (int bit = 0; bit < 32; bit++) {
            ll target = (1 << bit) - x;
            auto it = freq.find(target);
            
            if (it == freq.end()) {
                continue;
            }

            if (target > x) {
                count += (amount * it -> second);
            } else if (target == x) {
                count += (amount * (amount - 1)) / 2;
            }
        }
    }

    cout << count << '\n';
}

int main() {
    inout;
    int t = 1;
    // std::cin >> t;
    
    while (t--) solve();
}
