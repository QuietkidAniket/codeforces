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
	int n; cin>> n;
	int m; cin>> m;
	vector<vector<int>> adj(n+1);
	vector<vector<int>> back_edge(n+1);
	for(int i=0;i <m; i++){
	    int u,v;  cin>>u>>v;

		adj[u].push_back(v);
		back_edge[v].push_back(u);
	}

	vector<int> reachability(n+1,0); // reachability from n to node

	queue<int> q;
	q.push(n);
	reachability[n] = 1;
	while(!q.empty()){
	    int node = q.front();
		q.pop();

		for(int adjnode: back_edge[node]){
		    if(!reachability[adjnode]){
				q.push(adjnode);
				reachability[adjnode] =1;
			}
		}
	}

	vector<int> dp(n+1,-1); // stores the number of ways to come at n from node

	function<int(int)> f = [&](int node)->int{
	    if(node == n)return 1;
		if(dp[node] != -1) return dp[node];
	    int res = 0;
		for(int adjnode : adj[node]){
		    if(reachability[adjnode]){
				res += f(adjnode);
				res %= MOD;
			}
		}
	    return dp[node] = res;
	};

	cout << f(1) <<endl;


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
