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

int n;
vector<ll> arr, ans;
vector<vector<int>> graph;

void dfs(int parent, int node, ll add, ll sub) {
    ans[node] = add;
    
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            dfs(node, neighbor, max(arr[neighbor], arr[neighbor] + sub), max(-arr[neighbor], -arr[neighbor] + add));
        }
    }
}

void solve() {
    cin >> n;
    arr.assign(n + 1, 0), ans.assign(n + 1, 0);
    graph.assign(n + 1, {});
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    dfs(-1, 1, (ll)arr[1], (ll)-arr[1]);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main() {
    inout;
    int t = 1;
    cin >> t;
    
    while (t--) solve();
}
