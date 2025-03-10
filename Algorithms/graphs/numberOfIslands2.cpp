#include <bits/stdc++.h>
using namespace std;


class DisjointSet{
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        // for 1 based indexing and 0 based indexing both
        for(int i = 0 ;i <= n ;i++){
            parent[i]= i;
        }
    }

    int findUPar(int node){
        if(node == parent[node])return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};


class Solution{
    public:
    inline bool check(int row, int col, int m, int n){
        return row <m && col < n && row >= 0 && col >= 0;
    }

    // returns the count of islands after each update/ query
    vector<int> numberOfIslands(int m, int n, vector<vector<int>> &operators){
        DisjointSet ds(m * n);
        int direction[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        // we keep a track of which cells are land using the vis array
        int vis[m][n];
        memset(vis, 0 , sizeof vis);
        
        int count = 0; // keeps a count of the number of islands
        vector<int> ans;
        for(const auto it: operators)
        {
            int row = it[0];
            int col = it[1];

            if(vis[row][col]){
                ans.push_back(count);
                continue;
            }

            int node_no = row*n + col;
            vis[row][col] =1 ; // mark the node as land
            // according to our algorithm, we initially increase the count by one prior to checking
            // the adjcacent components if any
            count++;

            // check the adjcacent nodes
            for(int i = 0 ;i < 4; i++){
                int nrow = row + direction[i][0];
                int ncol =  col + direction[i][1];

                // check whether the adjcacent node is visited, 
                // if already visited, we need to find the union of that adjcacent node with the node
                if(check(nrow, ncol, m, n) && vis[row][col]){
                    int adjnode_no = nrow * n + ncol;
                    // if on adjcacent there is some other component, then unite the node to the ajdcacent
                    if(ds.findUPar(adjnode_no) != ds.findUPar(node_no)){
                        // decrease the number of components as we perform a union of two components
                        count--;
                        ds.unionBySize(adjnode_no, node_no);
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
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