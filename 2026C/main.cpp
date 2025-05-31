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
    string s;
    cin >> n >> s;

    stack<int> one, zero;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero.push(i + 1);
        } else {
            one.push(i + 1);
        }
    }

    if (zero.empty()) {
        ll l = 1, r = n, sum = 0;
        while (l < r) {
            sum += l;
            l++;
            r--;
        }

        if (n & 1) {
            sum += (n / 2) + 1;
        }

        cout << sum << '\n';
        return;
    }
    
    ll total = 0;
    while (!zero.empty() && !one.empty()) {
        // extract one and get all the zeros that are aback
        int free = one.top();

        if (zero.top() < free) {
            total += zero.top();
            zero.pop();
            one.pop();
        } else {
            while (!zero.empty() && !one.empty() && zero.top() > one.top()) {
                total += zero.top();
                zero.pop();
            }
        }
    }

    if (!zero.empty()) {
        while (!zero.empty()) {
            total += zero.top();
            zero.pop();
        }
    } else if (!one.empty()) {
        int m = one.size(), front = 0;
        int arr[m] = {0};
        while (!one.empty()) {
            arr[front] = one.top();
            front++;
            one.pop();
        }

        reverse(arr, arr + m);
        ll l = 0, r = m - 1;
        while (l < r) {
            total += arr[l];
            l++;
            r--;
        }

        if (m & 1) {
            total += arr[m/2];
        }
    } 
    cout << total << '\n';
}

int main() {
    inout;
    int t = 1;
    std::cin >> t;
    
    while (t--) solve();
}
