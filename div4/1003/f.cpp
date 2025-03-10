#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

vector<vector<int>> adjl;
vector<bool> vis;
unordered_map<int, int> num;

bool dfs(int node, int k, int count, const int target){
  if(num[node] == target)count++;
  if(k/2 < count && k>=2)return true;
  vis[node] = true;
  for(const auto& adjnode: adjl[node]){
    if(!vis[adjnode]){
      bool res = dfs(adjnode, k+1,count, target);
      if(res){  
        vis[node] = false;
        return true;
      }
    }
  }
  vis[node] = false;
  // by default 
  return false;
}


void Solve(){
  int n;
  cin>> n;
  // value assigned to ith vertice
  for(int i = 0; i< n; i++)
  {
    cin >> num[i];
  }
  adjl.resize(n+1);
  vis.resize(n+1);
  int u, v;
  for(int i = 0; i < n-1; i++){
    cin >> u>> v;
    adjl[u].push_back(v);
    adjl[v].push_back(u);
  }
  
  // try to visit all the nodes with the number i
  for(int i = 1; i <= n; i++){
    // if(num.find(i) == num.end()){
    //   cout << 0;
    //   continue;
    // }
    bool flag = false;
    for(int node = 1; node <= n; node++){
      if(!vis[node]){
        if(dfs(node, 1, 0, i)){
          cout << 1;
          flag =  true;
          break;
        }
      }
    }
    if(!flag)cout << 0;
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
  freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
  int tt = clock();
  #endif
  
  int t = 1;
  if(multi)cin>> t;
  while(t--){
  Solve();
  cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}