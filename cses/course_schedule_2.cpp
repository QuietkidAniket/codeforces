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
	vector<int> outdeg(n+1);
	for(int i = 0 ; i <m; i++){
	    int u, v; cin>>u>>v;
		adj[v].push_back(u);
		outdeg[u]++;
	}
	vector<int>  topo, vis(n+1,0);
	set<int> level;
	priority_queue<int> q;
	for(int node = 1; node <=n; node++){
	    if(outdeg[node] == 0)q.push(node);
	}
	while(!q.empty()){
		int node = q.top();
		q.pop();
		topo.push_back(node);
		for(int adjnode : adj[node]){
		    if(--outdeg[adjnode] == 0)q.push(adjnode);
		}
	}
	reverse(topo.begin(), topo.end());
	
	// for cses course schedule 2
	// for(int x: topo)cout << x << " ";
	
	// for codeforces 825:
	vector<int> inv(n+1);
	for(int i = 0; i < topo.size(); i++){
	    inv[topo[i]] = i+1;
	}
	for(int i =1; i <=n; i++){
	    cout << inv[i] << " ";
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
