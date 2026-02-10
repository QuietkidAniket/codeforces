// _______ Author : Anicetus_7 ____________
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  int a[n+1], b[n+1];
  for(int i =1;i <= n ; i++){
    cin>>a[i];
  }
  for(int i =1;i <= n ; i++){
    cin>>b[i];
  }
  vector<int> prefa(n+1), suffa(n+2);
  vector<int> prefb(n+1), suffb(n+2);
  prefa[0] = suffa[n+1] = 0;
  for(int i = 1; i <=n; i++){
    prefa[i] = max(a[i], prefa[i-1] + a[i]);
  }
  for(int i = n; i >=1; i--){
    suffa[i] = max(a[i], suffa[i+1] + a[i]);
  }
  prefb[0] = suffb[n+1] = 0;
  for(int i = 1; i <=n; i++){
    prefb[i] = max(b[i], prefb[i-1] + b[i]);
  }
  for(int i = n; i >=1; i--){
    suffb[i] = max(b[i], suffb[i+1] + b[i]);
  }

  int mx =-INF;
  for(int i = 1; i <= n; i++){
    // int p1= prefa[i], p2 = prefb[i];
    // int s1= suffa[i], s2 = suffb[i];
    // vector<int> z = {suffa[i], prefa[i],prefa[i] + suffa[i]- a[i]};
    // int res1=  *max_element(z.begin(), z.end()); 
    // z = {suffb[i], prefb[i], prefb[i] + suffb[i]- b[i]};
    // int res2=  *max_element(z.begin(), z.end()); 
    int res1 = prefa[i] + suffa[i] - a[i];
    int res2 = prefb[i] + suffb[i] - b[i];
    mx = max(mx, res1+res2);

  }
  cout <<mx <<endl;
  

}


//_______________[MAIN]__________________
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}
