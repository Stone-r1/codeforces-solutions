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
    int n;
    string s;
    cin >> n >> s;
    
    int front = 0, left = 0;
    if (s[0] == '1') {
        while (front < n && s[front] != '0') front++;
        while (front < n && s[front] == '0') front++;
    } else {
        while (front < n && s[front] == '0') front++;
        left = front;
        while (front < n && s[front] != '0') front++;
        if (front != n) {
            while (front < n && s[front] == '0') front++;
        } else {
            left = 0;
            front = 0;
        }
    }
    
    reverse(s.begin() + left, s.begin() + front);
    int transition = 0, similar = 0;
    if (s[0] == '1') {
        transition++;
    } else {
        similar++;
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i+1]) {
            similar++;
        } else {
            transition++;
        }
    }
    
    cout << transition * 2 + similar << '\n';
}

int main() {
    inout;
    int t = 1;
    cin >> t;
    
    while (t--) solve();
}
