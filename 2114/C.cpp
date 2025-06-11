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
#define inout ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAXL = 1e18, MAX = 1e9;
const ll INV2 = 500000004;


void solve() {
    int n, tot = 0;
    cin >> n; 
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int len = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i+1]) {
            continue;
        }
        
        if (arr[i] + 1 == arr[i+1]) {
            len++;
        } else {
            if (len == 1) {
                tot++;
                continue;
            }
            
            tot += (len + 1) / 2;
            len = 1;
        }
    }
    
    tot += (len + 1) / 2;
    cout << tot << '\n';
}

int main() {
    inout;
    int t = 1;
    cin >> t;
    
    while (t--) solve();
}
