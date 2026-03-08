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
    int n, m, l; cin>>n>>m>>l;
    
    vector<int> a(l); for(auto& x : a)cin>> x;
    vector<vector<int>> adj(n+1);
    for(int i =0; i <m; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
   queue<pair<int, int>> q; // {node, parity}
    q.push({1, 0});
    
    vector<array<int, 2>> dist(n+1, {INF, INF});

    dist[1][0] = 0;
    
    while(!q.empty()){
        auto [node, par] = q.front();
        q.pop();
        
        for(int adjnode : adj[node]){
            if(dist[node][par] +1 < dist[adjnode][!par]){
                dist[adjnode][!par] =  dist[node][par] + 1;
                q.push({adjnode, !par});
            }
        }
    }
    
    int sum = 0, smallest_odd = INF;
    for(int i =0 ;i  <l ;i++){
        sum += a[i];
        if(a[i] &1)smallest_odd  = min(smallest_odd, a[i]);
    }
	
	// for(int node = 1; node<= n; node++){cout << node << " : "<<dist[node][0] <<", " << dist[node][1] <<endl;}
	for(int node = 1; node<= n; node++){
	    if(sum%2==0){
		    if(sum-smallest_odd >= dist[node][1])cout <<1;
			else if(sum >= dist[node][0])cout<<1;
			else cout <<0;
		}else if(sum%2==1){
		    if(sum-smallest_odd >= dist[node][0])cout <<1;
			else if(sum >= dist[node][1])cout<<1;
			else cout <<0;
		}else cout << 1;
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