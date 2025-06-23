/**
 *    author: Anicetus_7
 *    created: 2025-06-21 00:09:24
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n);
  int sum = 0;
  multiset<int> st;
  for(int i = 0; i< n; i++)
  {
    cin>>a[i] ;
    sum += a[i];
    st.insert(a[i]);
  }
  
  vector<int> ans;
  for(int i= 0; i <n;i++){
    sum -= a[i];
    st.erase(st.find(a[i]));
    if(sum%2==0 &&st.count(sum/2)  > 0){
      ans.push_back(i+1);
    }
    st.insert(a[i]);
    sum += a[i];
  }
  cout << ans.size() << '\n';
  for(auto& x : ans)cout << x << " ";
  cout << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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