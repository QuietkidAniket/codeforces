/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    int n,q; cin>>n>>q;
    vector<int> par(n+1);
    par[1] = 0;
    vector<vector<int>> adj(n+1);
    for(int i =2; i<=n; i++){
        cin>>par[i];
        adj[par[i]].push_back(i);
    }
    
    vector<vector<int>> anc(n+1, vector<int>(21, 0));
    
    queue<int> qu;
    qu.push(1);
    while(!qu.empty()){
        int node = qu.front();
        qu.pop();
        anc[node][0] = par[node]; 
        for(int i =1;i< 21; i++){
            anc[node][i] = anc[anc[node][i-1]][i-1];
        }
        for(int adjnode :  adj[node]){
            qu.push(adjnode);
        }
    }
    for(int i =0;i < q; i++){   
        int node, k; cin>>node>>k;
        int cur = node;
        for(int bit = 0; bit < 21; bit++){
            if(k &(1<<bit)){
                cur = anc[cur][bit];
            }
        }
        cout << (!cur? -1 : cur) <<endl;
    }

}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
  for(int i = 1; i <= t; i++)
    {
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
