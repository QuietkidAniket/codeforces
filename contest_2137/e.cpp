/**
 *    author: Anicetus_7
 *    created: 2025-09-07 21:27:11
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vector<int> find(const vector<int>& a){
    int n = a.size();
    vector<int> freq(n + 2, 0);
    for (int x : a) if (x <= n) freq[x]++;
    int mex = 0;
    while (mex < n + 2 && freq[mex] > 0) mex++;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (freq[a[i]] > 1 || a[i] >= mex) res[i] = mex;
        else res[i] = a[i];
    }
    return res;
}
 
void Solve(){
  int n,k; cin>>n>>k;
  vector<int> a(n);
 
  for(auto& x : a)cin>> x;
 
  auto prev =a;
  for(int i =1; i <=k ;i++){
    vector<int> res = find(a);
    if(prev == res){
      if(i &1){
        if(k &1){
          cout << accumulate(res.begin(), res.end(), 0ll);
        }else if(k % 2== 0){
          cout << accumulate(a.begin(), a.end(), 0ll);
        }
      }else{
        if(k &1){
          cout << accumulate(a.begin(), a.end(), 0ll);
        }else if(k % 2== 0){
          cout << accumulate(res.begin(), res.end(), 0ll);
        }
      }
      cout << endl;
      return;
    }
    prev = a;
    a = res;
  }
 
  cout << accumulate(a.begin(), a.end(),0ll) << endl;
  
}

int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}