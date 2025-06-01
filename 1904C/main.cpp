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
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // k >= 3 and the rest
    if (k >= 3) {
        cout << "0\n";
    } else {
        sort(arr.begin(), arr.end());
        ll minElem = arr[0];
        for (int i = 1; i < n; i++) {
            minElem = min(minElem, arr[i] - arr[i-1]);
        }

        if (k == 1) {
            cout << minElem << '\n';
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    ll minVal = arr[j] - arr[i];
                    auto it = lower_bound(arr.begin(), arr.end(), minVal);

                    if (it != arr.end()) {
                        minElem = min(minElem, llabs(minVal - *it)); 
                    } 
                    if (it != arr.begin()) {
                        minElem = min(minElem, llabs(minVal - *(prev(it))));
                    }
                }
            }
            cout << minElem << '\n';
        }
    }
}

int main() {
    inout;
    int t = 1;
    std::cin >> t;
    
    while (t--) solve();
}
