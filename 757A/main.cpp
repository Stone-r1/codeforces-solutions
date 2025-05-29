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
    string s;
    cin >> s;

    unordered_map<char, int> freq;
    for (char e : s) {
        freq[e]++;
    }
    cout << min({freq['B'], freq['u'] / 2, freq['l'], freq['b'], freq['a'] / 2, freq['s'], freq['r']});
    
}

int main() {
    inout;
    int t = 1;
    // std::cin >> t;
    
    while (t--) solve();
}
