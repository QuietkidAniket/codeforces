#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};

class DisjointSet {
    unordered_map<pair<int,int>, int, pair_hash> Size;
    unordered_map<pair<int, int>, pair<int,int>, pair_hash> parent;

public:
    pair<int, int> findUParent(pair<int, int> node) {
        if(parent.find(node) == parent.end()){
            parent[node] = node;
            return node;
        }
        pair<int,int> p = parent[node];
        if(p.first == node.first && p.second == node.second) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(pair<int, int> u, pair<int, int> v) {
        auto ulp_u = findUParent(u);
        auto ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;

        if (Size[ulp_u] < Size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            Size[ulp_v] += Size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            Size[ulp_u] += Size[ulp_v];
        }
    }
};

class Solution {
public:
    int manhattan(pair<int, int> u, pair<int, int> v) {
        return abs(u.first - v.first) + abs(u.second - v.second);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<tuple<int, pair<int, int>, pair<int, int>>, vector<tuple<int, pair<int, int>, pair<int, int>>>, greater<>> pq;


        for (int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                pair<int, int> u = {points[i][0], points[i][1]};
                pair<int, int> v = {points[j][0], points[j][1]};
                pq.push({manhattan(u, v), u, v});
            }
        }

        DisjointSet ds;
        int sum = 0;

        while (!pq.empty()) {
            auto [wt, u, v] = pq.top();
            pq.pop();
            if (ds.findUParent(u) != ds.findUParent(v)) {
                ds.unionBySize(u, v);
                sum += wt;
            }
        }
        return sum;
    }
};



void solve(){
    Solution obj;
    string exp;
    while( (cin >> exp) )
    
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    solve();
    
    
    return 0;
}