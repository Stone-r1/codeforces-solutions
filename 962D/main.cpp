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

    vector<int> arr(n);
    map<ll, set<ll>> freq;
    set<pair<ll, ll>> final;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]].insert(i);
    }

    while (!freq.empty()) {
        auto it = freq.begin();
        ll value = it -> first;
        auto& idx = it -> second;

        while (idx.size() >= 2) {
            auto it1 = idx.begin();
            auto it2 = next(it1);

            ll newIdx = *it2;
            freq[value * 2].insert(newIdx);

            idx.erase(it1);
            idx.erase(it2);
        }
        if (idx.size() >= 1) {
            final.insert({*idx.begin(), value});
        }

        freq.erase(it);
    }

    cout << final.size() << '\n';
    for (auto& [first, second] : final) {
        cout << second << " ";
    }
}

int main() {
    inout;
    int t = 1;
    // std::cin >> t;
    
    while (t--) solve();
}
