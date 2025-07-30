#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

int numOfSubsequences(string s) {
    int n = s.size();

    // Precompute prefix counts
    vector<int> prefixL(n + 1, 0), prefixLC(n + 1, 0);
    int cntL = 0, cntLC = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') cntL++;
        else if (s[i] == 'C') cntLC += cntL;

        prefixL[i + 1] = cntL;
        prefixLC[i + 1] = cntLC;
    }

    // Precompute suffix counts
    vector<int> suffixT(n + 1, 0), suffixCT(n + 1, 0);
    int cntT = 0, cntCT = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'T') cntT++;
        else if (s[i] == 'C') cntCT += cntT;

        suffixT[i] = cntT;
        suffixCT[i] = cntCT;
    }

    // Count base LCT subsequences
    int base = 0;
    int l = 0, lc = 0;
    for (char ch : s) {
        if (ch == 'L') l++;
        else if (ch == 'C') lc += l;
        else if (ch == 'T') base += lc;
    }

    int ans = base;

    // Try inserting 'L', 'C', or 'T' at every position
    for (int i = 0; i <= n; ++i) {
        // Insert 'L' at pos i: contributes suffixCT[i]
        ans = max(ans, base + suffixCT[i]);

        // Insert 'C' at pos i: contributes prefixL[i] * suffixT[i]
        ans = max(ans, base + prefixL[i] * suffixT[i]);

        // Insert 'T' at pos i: contributes prefixLC[i]
        ans = max(ans, base + prefixLC[i]);
    }

    return ans;
}

void Solve() {
    string s;
    cin >> s;
    cout <<s << " : " <<numOfSubsequences(s) << '\n';
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) Solve();
    return 0;
}