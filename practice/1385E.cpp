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
	int m; cin>>m;
	vector<vector<int>> adj(n+1);
	vector<pair<int,int>> edges;
	for(int i =0 ;i <m; i++){
	    int c,u,v; cin>>c>>u>>v;
		if(c){
		    adj[u].push_back(v);
		}
		edges.push_back({u,v});
	}
	vector<int> ord, vis(n+1, 0);
	function<void(int)> f=  [&](int node){
	    vis[node] = 1;
		for(int adjnode: adj[node]){
		    if(vis[adjnode])continue;
			f(adjnode);
		}
	    ord.push_back(node);
	};

	for(int node = 1; node <=n ;node++){
	    if(!vis[node])f(node);
	}
	reverse(ord.begin(), ord.end());
	vector<int> inv(n+1,0);
	for(int i = 0; i < n; i++){
	    inv[ord[i]] = i;
	}
	bool flag = false;
	for(int node = 1; node <= n; node++){
	   for(int adjnode : adj[node]){
			if(inv[adjnode] < inv[node]){
			    flag = true;
			}
		}
	}
	if(flag){
	    cout <<"NO\n";
		return;
	}
	cout <<"YES\n";
	for(auto [u,v] : edges){
	    if(inv[u] > inv[v]){
			swap(u,v);
		}
		cout << u <<" "<< v << endl;
	}

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
