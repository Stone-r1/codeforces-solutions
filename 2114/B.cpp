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
    int n, k;
    string s;
    cin >> n >> k >> s;

    int one = 0;
    for (int e : s) if (e == '1') one++;

    one = abs(2 * one - n) / 2;
    cout << ((k >= one && (k & 1) == (one & 1)) ? "YES\n" : "NO\n"); 
}

int main() {
    inout;
    int t = 1;
    cin >> t;
    
    while (t--) solve();
}
