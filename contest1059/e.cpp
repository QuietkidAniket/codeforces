/**
 *    author: Anicetus_7
 *    created: 2025-10-18 17:49:53
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());



void Solve(){
  int n,k; cin>>n>>k;
  vector<int> a(n);

  unordered_set<int> st;
  for(int i =1;i <=n ;i++){ 
    st.insert(i);
  }
  for(int i = 0 ;i < n; i++){
    cin>>a[i];
    st.erase(a[i]);
  }

  if(st.size() == 0){
    for(int i =0 ; i < n && k; i++, k--){
      cout << a[i] << " "; 
    }
  }else{
    for(auto it =st.begin() ; it !=st.end() && k; it++, k--){
      cout << *it << " "; 
    }
    int elem = a.back();
    for(int i =1; i <=n && k;i++){
      if(st.find(i) == st.end() && elem != i){cout << i << " ";k--;}
    }
    if(k)cout << elem;
  } 
  cout << endl;
  
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