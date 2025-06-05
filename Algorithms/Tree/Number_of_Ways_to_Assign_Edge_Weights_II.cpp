#define ll long long
const int MOD = 1e9 + 7;


/* Assuming root node  at 1 */


class Solution {
public:
    vector<vector<int>> tree;
    vector<int> depth, parent;

    void dfs(int node, int par) {
        for (int adjnode : tree[node]) {
            if (adjnode != par) {
                depth[adjnode] = depth[node] + 1;
                parent[adjnode] = node;
                dfs(adjnode, node);
            }
        }
    }

    int lca(int u, int v) {
        while (u != v) {
            if (depth[u] > depth[v]) u = parent[u];
            else v = parent[v];
        }
        return u;
    }

    ll modPow(ll base, ll exp) {
        ll res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size()+1;
        tree.assign(n + 1, vector<int>());
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        depth.assign(n + 1, 0);
        parent.assign(n + 1, 0);
        dfs(1, 0); // root at node 1

        vector<int> answer;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            int ancestor = lca(u, v);
            int edgeCount = depth[u] + depth[v] - 2 * depth[ancestor];
            if (edgeCount == 0) {
                answer.push_back(0);
            } else {
                answer.push_back(modPow(2, edgeCount - 1));
            }
        }

        return answer;
    }
};
    