/**
 *    author: Anicetus_7
 *    created: 2025-12-05 20:29:06
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAXw (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,k; cin>>n>>k;
  int a[n+1];
  a[0] = 0;
  for(int  i=1; i<=n ;i++)cin>>a[i];

  sort(a, a + n+1);
  unordered_map<int, int> freq;
  for(int i=1; i<= n; i++)freq[a[i]]++;
  unordered_map<int, int> vis;
  
  vector<int> vec;
  bool flag= false;
  for(int i = 1; i <= n ; i++){
    if(vis[a[i]])continue;
    if((k/a[i])*a[i] > k){
      flag = true;
      break;
    }
    for(int j= a[i];j <= k; j+=a[i]){
      if(freq[j]==0){
        flag = true; break;
      }
    }
    if(flag)break;
    vec.push_back(a[i]);
    for(int j= a[i];j <= k; j+=a[i]){
      vis[j] = 1;
    }
  }
  if(flag ){
    cout << -1 << endl;
  }else{
    cout << vec.size() << endl;
    for(auto& x : vec)cout << x << " ";
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