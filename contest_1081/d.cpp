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
    int n; cin>>n;
    vector<vector<int>> adj(n+1);
    vector<int> a(n+1); 
    
    for(int node =1 ;node <=n ;node++)cin>>a[node];
    
    for(int i = 0 ; i <n-1; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // dp[node][0] -> sum without operation in subtree, dp[node][1] =  sum with a single operation in the subtree
    vector<vector<int>> dp(n+1, vector<int>(2,0)); 
    vector<int> depth(n+1, 0), mxdepth(n+1, 0), sum(n+1, 0), vis(n+1,0);
    
    
    function<void(int)> dfs = [&](int node)->void{
        vis[node] = 1;
        
        mxdepth[node] = depth[node];
        vector<int> vec;
        sum[node] = a[node];
        
        multiset<int> st;
        for(int adjnode: adj[node]){
            if(vis[adjnode])continue;
            depth[adjnode] = depth[node] + 1;
            dfs(adjnode);
            
            mxdepth[node] = max(mxdepth[node], mxdepth[adjnode]);
            sum[node] += sum[adjnode];
            dp[node][0] += dp[adjnode][0]+sum[adjnode];
            vec.push_back(adjnode);
            st.insert(mxdepth[adjnode]);
        }
        int m = vec.size();
        dp[node][1] = dp[node][0];
        for(int i = 0; i <m; i++){
            st.erase(st.find(mxdepth[vec[i]]));
            dp[node][1] = max(dp[node][1], dp[node][0] - dp[vec[i]][0]+  dp[vec[i]][1]);
            if(m > 1){
                int curmx = *st.rbegin();
                int res = (curmx - depth[node])*(sum[vec[i]]);
                dp[node][1] = max(dp[node][1], res+ dp[node][0]);
            }
            st.insert(mxdepth[vec[i]]);
        }
        st.clear();
    };
    dfs(1);
    
    for(int node =1 ;node <= n ;node++){
        cout << max(dp[node][0], dp[node][1]) <<" ";
    }
    cout <<endl;
    
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
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
