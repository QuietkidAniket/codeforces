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
	vector<string> a(n);
	for(auto& x : a)cin>> x;

	vector<vector<int>> adj(26); // u -> v : u < v in dictionary
	vector<int> indegree(26,0);

	for(int i =0 ; i < n-1; i++){
	    bool flag= false;
		for(int k=0; k < min(a[i].size(), a[i+1].size()); k++){
		    if(a[i][k] != a[i+1][k]){
    		    adj[a[i][k]- 'a'].push_back(a[i+1][k]-'a');
    			indegree[a[i+1][k] - 'a']++;
				flag = true;
				break;		
			}
		}
		if(!flag && a[i].size() > a[i+1].size()){
		    cout << "Impossible\n";
			return;
		}
	}
	
	queue<int> q;
	for(int node =0; node< 26; node++){
	    if(!indegree[node])q.push(node);
	}

	vector<int> topo;
	while(!q.empty()){
	    int node = q.front();
		q.pop();
		topo.push_back(node);
		for(int adjnode: adj[node]){
		    if(--indegree[adjnode]==0)q.push(adjnode);
		}
	}

	if(topo.size() != 26){
	    cout << "Impossible\n";
	}else{
	    for(auto& x: topo){
			cout << (char)(x +'a');
		}
		cout <<endl;
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
