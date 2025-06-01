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

    vector<pair<int, int>> arr(n);
    int raw[n];
    for (int i = 0; i < n; i++) {
        cin >> raw[i];
        arr[i].first = raw[i];
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    int ans[n] = {0};
    ll pos = 0, count = arr[0].first;
    for (int i = 0; i < n; i++) {
        if (pos < i) {
            pos++;
            count += arr[pos].first;
        }

        while (pos + 1 < n && count >= arr[pos + 1].first) {
            pos++;
            count += arr[pos].first;
        }

        ans[arr[i].second] = pos; 
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " "; 
    } 
    cout << '\n';
}

int main() {
    inout;
    int t = 1;
    std::cin >> t;
    
    while (t--) solve();
}
