/**
 *    author: Anicetus_7
 *    created: 2025-09-13 12:24:44
**/
#include <bits/stdc++.h>
using namespace std;
#define INF (long long)1e18
#define MOD (long long)(1e9 + 7)

unordered_map<string, vector<vector<string>>> adjl;
unordered_map<string, long long> dp;
// unordered_set<string>  vis;

long long dfs(const string &node) {
    if (adjl.find(node) == adjl.end()) return 0;
    if (dp.count(node)) return dp[node];
    // if (vis.count(node)) return INF; 
    // assert(vis.count(node) == 0);

    // vis.insert(node);
    long long res = INF / 2;
    for (auto &vec : adjl[node]) {
        long long cur = 0;
        for (auto &adjnode : vec) {
            cur += dfs(adjnode);
            if (cur >= res) break;
        }
        res = min(res, cur);
    }
    // vis.erase(node);
    return dp[node] = res + 1;
}

void Solve() {
    int n; cin >> n;
    adjl.clear();
    dp.clear();
    // vis.clear();
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        auto pos = s.find('=');
        string u = s.substr(0, pos);
        string right = s.substr(pos + 1);

        vector<string> v;
        string token;
        stringstream ss(right);
        while (getline(ss, token, '+')) {
            if (!token.empty()) v.push_back(token);
        }
        adjl[u].push_back(v);
    }

    string target; cin >> target;
    cout << dfs(target) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}