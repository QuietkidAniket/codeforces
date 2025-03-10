#include <bits/stdc++.h>
using namespace std;


class DisjointSet{
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
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
    int removeStones(vector<vector<int>>& stones){
        int maxRow = 0, maxCol = 0;
        int n = stones.size();
        for(const auto stone : stones){
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> stoneNodes;

        // building the disjoint set of components
        for(const auto& stone :stones){
            int nodeRow = stone[0];
            int nodeCol = stone[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        // counting the number of components
        int count= 0; 
        for(const auto& x : stoneNodes){
            if(ds.findUPar(x.first) == x.first){
                count++;
            }
        }
        return n - count;

    }

};

