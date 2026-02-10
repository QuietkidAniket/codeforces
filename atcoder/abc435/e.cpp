/**
 *    author: Anicetus_7
 *    created: 2025-12-14 09:47:16
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define pii pair<int,int>
#define fi first
#define si second

struct cover_set{
  set<pii> st;
  int cnt = 0;
  void insert(int l, int r){
    vector<pii> b;
    // l <= li
    auto it = st.lower_bound({l, -INF});
    if(it != st.begin()){
      it--;
      if(it->si < l)it++; 
    }
    int mnl = l, mxr =r;
    while(it != st.end()){
      if(r < it->fi)break;
      mnl = min(mnl, it->fi);
      mxr = max(mxr, it->si);
      cnt -= (it->si - it->fi +1);
      // _____________ GENIUS method to remove an element and proceed to next element ________
      it = st.erase(it);
    }
    cnt+= mxr - mnl +1;
    st.insert({mnl, mxr});
  }
  int query(){
    return cnt;
  }
};

void Solve(){
  int n,q; cin>>n>>q;
  cover_set cs;
  while(q--){
    int l, r; cin>>l>>r;
    cs.insert(l , r);
    cout << ( n- cs.query()) << " ";
  }
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