/**
 *    author: Anicetus_7
 *    created: 2025-11-15 10:08:39
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  string a; cin>>a;
  int n = a.size();
  for(int i = 0;i < n-1; i++){
    if(a[i] =='>' && a[i+1] == '<'){
      cout << -1 << endl;
      return ;
    }
    else if(a[i] =='*' && a[i+1] == '*'){
      cout << -1 << endl;
      return;
    }else if(a[i] == '>' && a[i+1] == '*'){
      cout << -1 << endl;
      return;
    }else if(a[i] == '*' && a[i+1] == '<'){
      cout << -1 << endl;
      return;
    }
  }
  int ans = 0;
  // calculate the largest contiguous <<<*
  int l = 0;
  for(int r = 0;r < n; r++){
    if(a[r] == '<' || a[r] == '*'){
      ans = max(r-l+1, ans);
    }else l = r+1;
  }
  ans = max(ans, n- l);
  // calculate the largest contiguous *>>>
  l = 0;
  for(int r = 0;r < n; r++){
    if(a[r] == '>' || a[r] == '*'){
      ans = max(r-l+1, ans);
    }else l = r+1;
  }
  ans = max(ans, n- l);
  cout << ans << endl;
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