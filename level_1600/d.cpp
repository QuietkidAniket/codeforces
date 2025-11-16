#include <bits/stdc++.h>
using namespace std;
#define ll long long

// DSU template from your codeforces submissions
class DisjointSet{
public:
    vector<int> parents;
    vector<int> sizes;
    DisjointSet(int size) : parents(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) { parents[i] = i; }
    }

    int find(int x) {
        return parents[x] == x ? x : (parents[x] = find(parents[x]));
    }

    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) return false;

        if (sizes[x_root] < sizes[y_root]) swap(x_root, y_root);
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }
};

class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();

        // Base alternating sum of original array (optional)
        ll ans = 0, z = 1;
        for (int i = 0; i < n; i++) {
            ans += nums[i] * z;
            z *= -1;
        }

        // Initialize DSU
        DisjointSet dsu(n);
        for (auto& e : swaps) dsu.unite(e[0], e[1]);

        // Group indices by their component representative
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; i++) {
            components[dsu.find(i)].push_back(i);  // USE find()!
        }

        ll res = 0;
        for (auto& [c, vec] : components) {
            vector<int> a;
            int even = 0, odd = 0;
            for (int idx : vec) {
                a.push_back(nums[idx]);
                if (idx % 2 == 0) even++;
                else odd++;
            }

            sort(a.begin(), a.end()); // ascending

            int sz = a.size();
            for (int i = sz - 1; i >= max(0, sz - even); i--) res += a[i]; // largest → even
            for (int i = 0; i < min(odd, sz); i++) res -= a[i];            // smallest → odd
        }

        return res;
    }
};

//------------------ Test Case ------------------//
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2};
    vector<vector<int>> swaps = {{0,2}, {1,3}, {2,3}};

    ll result = sol.maxAlternatingSum(nums, swaps);
    cout << "Output: " << result << "\n"; // Expected: 1
}