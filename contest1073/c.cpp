/**
 *    author: Anicetus_7
 *    created: 2026-01-17 20:49:08
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
  string a; cin>>a;
  string s =a;
  sort(s.begin(), s.end());
  if(s == a){
    cout << "Bob\n";
    return;
  }
  int prev = -1;
  int idx = n-1;
  int cnt =0;
  for(int i = 0 ; i <n; i++){
    // if(a[i] == '0')idx = max(idx,i);
    cnt+= a[i] =='0';
  }
  vector<int> ans;
  for(int i =0 ;i < cnt; i++){
    if(a[i] == '1')ans.push_back(i+1);
  }
  for(int i =cnt;i < n; i++){
    if(a[i] == '0')ans.push_back(i+1);
  }
  cout << "Alice\n";
  // ans.push_back(idx+1);
  // // cout << "cnt : " << cnt << endl;;
  // if(cnt%2 == 0){
  //   prev = idx;
  //   int res = 0;
  //   for(int i = idx+1; i <n; i++){
  //     if(a[i] == '0'){
  //       if(prev != i-1){
  //         res++;
  //       }
  //       if(res == 2)break;
  //       ans.push_back(i+1);
  //       prev = i;
  //     }
  //   }
  // }else{
  //   prev = idx;
  //   int res = 0;
  //   for(int i = idx+1; i <n; i++){
  //     if(a[i] == '0'){
  //       if(prev != i-1){
  //         break;
  //       }
  //       ans.push_back(i+1);
  //       prev = i;
  //     }
  //   }
  // }
  cout << ans.size() <<endl;
  for(int x : ans)cout << x << " ";
  cout <<endl;
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