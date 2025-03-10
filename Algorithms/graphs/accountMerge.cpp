#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> size, parent;
    DisjointSet(int n ){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i< n; i++)
        {
            parent[i] = i;
        }
    }
    int find_parent(int node){
        if(parent[node] == node)return node;
        return parent[node] = find_parent(parent[node]);
    }
    
    void union_by_size(int u, int v){
        int ulp_u = find_parent(u);
        int ulp_v = find_parent(v);
        if(ulp_u == ulp_v)return;

        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_v;
            size[ulp_u] += size[ulp_v];
        }else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }

};

class Solution{
    public:
    vector<vector<string>> accountMerge(vector<vector<string>> accounts){
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string,int> mapMailNode;

        for(int i = 0; i < n; i++){
            // we iterate through all the mails for the ith node with name accounts[i][0]
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];   
                // if not present, add to the map
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }else{ // if already present, try joining the components
                    ds.union_by_size(i, mapMailNode[mail]);
                }
            }
        }
        vector<vector<string>> mailMerged(n);
            for(const auto& x : mapMailNode)
            {
                string mail = x.first; int node = ds.find_parent(x.second);
                // append the mail to the correct ultimate parent as decided by Disjoint set
                mailMerged[node].push_back(mail);
            }
        
        // parse the answer from the merged account data
        vector<vector<string>> ans;
        for(int i = 0 ;i < n;i++){
            if(mailMerged[i].size() == 0)continue;
            sort(mailMerged[i].begin(), mailMerged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]); // original name to be appended first
            for(const auto x : mailMerged[i]){
                temp.push_back(x);
            }
            ans.push_back(temp);
        }  
        return ans;
    }

};