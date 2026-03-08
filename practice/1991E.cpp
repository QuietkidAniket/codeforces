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
	int n,m; cin>>n>>m;
	vector<vector<int>> adj(n+1);
	for(int i =0 ;i< m; i++){
	    int u, v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> colour(n+1,-1);
	vector<vector<int>> comp(2);
	function<bool(int,int)> dfs = [&](int node, int col){
	    colour[node] = col;
		comp[col].push_back(node);
		for(int adjnode: adj[node]){
    		if(colour[adjnode] != -1){
    		    if(colour[adjnode] != 1-col)return false;
                else continue;
    		}
            if(!dfs(adjnode, 1-col))return false;
		}
		return true;
	};
	map<int,int> mp;
	if(dfs(1, 0)){ // choose bob
	    cout << "Bob\n";
		cout.flush();
		for(int i  =0 ;i < n; i++){
		    int x, y;
            cin >> x >> y;
            // if (x > y) {
            //     swap(x, y);
            // }
            int r = 6 - x - y;
            if (comp[0].empty()) {
                cout << comp[1].back() << " " << (r == 2 ? 3 : 2) << endl;
                comp[1].pop_back();
                continue;
            }
            if (comp[1].empty()) {
                cout << comp[0].back() << " " << (r == 1 ? 3 : 1) << endl;
                comp[0].pop_back();
                continue;
            }
            if (r == 1) {
                cout << comp[1].back() << " " << 2 << endl;
                comp[1].pop_back();
            } else {
                cout << comp[0].back()  << " " << 1 << endl;
                comp[0].pop_back();
            }
    		cout.flush();
		}
	}else{ // choose alice
	    cout << "Alice\n";
		cout.flush();
		for(int node =1; node<=n; node++){
		    cout << "1 2\n";
			cout.flush();
		    // cout << node << " " << colour[node]+1 <<"\n";
			// cout.flush();
			int x, y; cin>>x>>y;
			if(x==-1 || y== -1){
			    cerr<<"error" << endl;
				return;
			}
		}
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
