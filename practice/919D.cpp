/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
	int n; cin>>n;
	int m; cin>>m;

	string s; cin>>s;
	vector<int> indegree(n+1,0);
	vector<vector<int>> adj(n+1);
	for(int i =0;i < m ; i++){
	    int u, v; cin>>u>>v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	queue<int> q;
	vector<vector<int>> dp(n+1, vector<int>(26));
	for(int node=1 ;node<=n;node++){
	    if(indegree[node] == 0)q.push(node);
	    dp[node][s[node-1]-'a']= 1;
	}
	
	int topo = 0, ans =0 ;
	while(!q.empty()){
	    int node = q.front();
		q.pop();
		topo++;
		for(int c= 0; c< 26; c++){
		    ans = max(ans, dp[node][c]);
		}
		for(int adjnode: adj[node]){
		    for(int c= 0; c< 26; c++){
				dp[adjnode][c] = max(dp[adjnode][c],dp[node][c] + (s[adjnode-1]-'a' == c));
			}
		    if(--indegree[adjnode] == 0)q.push(adjnode);
		}
	}

	if(topo < n){
	    cout << -1 << endl;
	}else cout << ans << endl;

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
