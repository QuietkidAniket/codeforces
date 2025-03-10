#include<bits/stdc++.h>
using namespace std;


class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        // for 1 based indexing and 0 based indexing both
        for(int i = 0 ;i <= n ;i++){
            parent[i]= i;
        }
    }

    int findUPar(int node){
        if(node == parent[node])return node;
        return parent[node] = findUPar(parent[node]);
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
        return row >=0 && col >=0 && row < m && col < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        // forming existing components using Disjoint Set
        for(int row = 0 ; row < n; row++){
            for(int col = 0 ; col < n; col++){    
                if(grid[row][col] == 0)continue;
                int node_no = row*n + col;
                for(int i = 0 ; i < 4; i++){
                    int nrow=  row + direction[i][0], ncol  = col + direction[i][1];
                    if(check(nrow, ncol, n, n) && grid[nrow][ncol] == 1){
                        int adjnode_no  = nrow * n + ncol;
                        ds.unionBySize(node_no, adjnode_no);
                    }
                }
            }
        }
        int mx= 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1)continue;
                set<int> components; // actually stores the ultimate parents of the adjcacent
                for(int i = 0 ; i < 4; i++){
                    int nrow = row + direction[i][0], ncol = col + direction[i][1];
                    if(check(nrow, ncol, n,n) && grid[nrow][ncol] == 1){
                        int adjnode_no = nrow * n + ncol;
                        components.insert(ds.findUPar(adjnode_no));
                    }
                }
                int tot_size = 1;
                for(const auto& component : components){
                    tot_size += ds.size[component];
                }
                mx = max(mx, tot_size);
            }
        }
        // in case there are no such connections possible
        // so we need to return the size of the largest component
        for(int i = 0; i < n*n ;i++){
            mx= max(mx, ds.size[ ds.findUPar(i) ] );
        }
        return mx;
    }
};

