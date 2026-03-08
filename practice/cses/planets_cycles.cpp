/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i =1;i <=n; i++){
        cin>>a[i];
    }
    vector<int> vis(n+1,0);
    vector<int> dp(n+1,0);

    for(int i= 1; i<=n; i++){
        if(vis[i])continue;
        vector<int> path;
        int curr =i;
        while(!vis[curr]){
            vis[curr] = 1;
            path.push_back(curr);
            curr = a[curr];
        }
        if(dp[curr] != 0){  // cycle doesnt exist or previously calculated
            int val = dp[curr];
            while(!path.empty()){
                val++;
                dp[path.back()] = val;
                path.pop_back();
            }
        }else{ // cycle exists
            int idx =-1;
            for(int k =0; k< path.size(); k++){
                if(path[k] == curr){
                    idx = k;
                    break;
                }
            }

            int cycle_len = path.size() - idx;
            for(int k =idx; k < path.size(); k++){
                dp[path[k]] = cycle_len;
            }
            for(int k = idx-1; k >=0; k--){
                dp[path[k]] = dp[path[k+1]]+1;
            }
            path.clear();
        }

    }

    for(int i = 1;i <=n ;i++){
        cout << dp[i] << " ";
    }
    cout<<endl;

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
