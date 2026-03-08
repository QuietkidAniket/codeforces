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

    auto query=[&](int idx)->vector<int>{
        cout<< "? " <<idx << endl; cout.flush();
        int m; cin>>m; if(m==-1)exit(0);
        vector<int> a(m); for(auto& x : a)cin>> x;
        return a;
    };

    vector<bool> done(n+1 ,false);
    vector<int> dp(n+1, 0);
    vector<pair<int,int>> ans;
    // dfs (node, ptr, path)
    function<void(int, int , vector<int>)> dfs = [&](int node, int ptr, vector<int> path)->void{
        ptr++;
        done[node] = true;
        dp[node] = 1;

        while(true){
            auto curr = query(ptr);
            bool ok = true;
            for(int i = 0; i < path.size(); i++){
                if(i>=curr.size() || path[i] != curr[i]){ok = false; }
            }
            if(!ok)break;
            int adjnode = curr.back();
            ans.push_back({node, adjnode});

            if(!done[adjnode])dfs(adjnode, ptr, curr);
            dp[node] += dp[adjnode];
            ptr += dp[adjnode];
        }
    };

    for(int i = 1; i <=n; i++){
        if(!done[i]){
            int sum = 0;
            for(int j =1;  j < i; j++)sum+= dp[j];
            dfs(i, sum + 1, {i});
        }
    }
    cout << "! " << ans.size() << endl;
    for(auto& [u,v]:  ans)cout << u <<" " << v << endl;
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
