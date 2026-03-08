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
    struct  entry{int a, b, c;};
    vector<entry> f(n);

    for(auto& [a, b, c] : f)cin>>a>>b>>c;

    auto check_above  = [&](entry& x, entry& y){
        int a = x.a-y.a;
        int b = x.b-y.b;
        int c = x.c-y.c;
        if(a== 0){
            if(b==0)return c > 0;
            return false;
        }else if(a > 0)return b*b -4*a*c < 0;
        else return false;
    };

    vector<vector<int>> adj(n), rev_adj(n);
    for(int i =0; i <n; i++){
        for(int j = 0; j < n; j++){
            if(check_above(f[i], f[j])){
                // cout << i+1<< " -> "<< j+1 << endl;
                adj[i].push_back(j);
                rev_adj[j].push_back(i);
            }
        }
    }
    vector<int> startlen(n,-1), endlen(n, -1);
    function<int(int)> dfs1 = [&](int node){
        if(startlen[node]!= -1)return startlen[node];
        int best = 0;
        for(int adjnode : adj[node]){
            best = max(best, dfs1(adjnode));
        }   
        return startlen[node] = 1 + best;
    };
    function<int(int)> dfs2 = [&](int node){
        if(endlen[node]!= -1)return endlen[node];
        int best = 0;
        for(int adjnode : rev_adj[node]){
            best = max(best, dfs2(adjnode));
        }
        return endlen[node] = 1 + best;
    };
    
    for(int i =0 ;i <n; i++){
       cout << dfs1(i) + dfs2(i) -1 <<" ";
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
