/**
 *    author: Anicetus_7
 *    created: 2025-08-24 20:59:10
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define pii pair<int,int> 
#define f first
#define s second

void Solve(){
  int n; cin>> n;
  // vector<int> dist(n+1,0);
  vector<pair<int,int>> dist;

  for(int i =1; i <=n;i++){
    cout << "? " << i <<" " <<n << " ";
    for(int j =1;j<=n; j++)cout << j<<" ";
    cout << endl;

    cout.flush();
    
    int x; cin>>x;
    if(x == -1)return;
    pair<int,int> p = {x,i};
    dist.push_back(p);
  }
  
  sort(dist.rbegin(), dist.rend());
  vector<int> ans;
  ans.push_back(dist[0].s);

  int k = 1;
  for(int i =1; i <n; i++){ 
    if(dist[0].f -k < dist[i].f)continue;
    cout << "? " << dist[0].s <<" " <<n-1<< " ";
    for(int j =0;j<n; j++)cout << dist[j].s<<" ";
    cout << endl;

    cout.flush();
    
    int x; cin>> x;
    if(x == -1)return;
    if(x != dist[0].f){
      ans.push_back(dist[i].s);
      k++;
    }
  }
  cout.flush();
  cout << "! "<< ans.size()<<" ";
  for(const auto& x : ans)
  {
   cout << x <<" "; 
  }
  cout << endl;
  cout.flush();
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}