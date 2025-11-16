/**
 *    author: Anicetus_7
 *    created: 2025-11-04 20:42:05
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,k; cin>>n >> k;
  vector<vector<int>> a(k+1);
  for(int i =1;i <= n; i++){
    int x; cin>>x;
    a[x].push_back(i);
  }

  multiset<int> st;

  int ans = n+1;
  for(int i =1;i <= k; i++){
    st.clear();
    a[i].push_back(0);
    a[i].push_back(n+1);
    sort(a[i].begin(), a[i].end());
    for(int j= 0; j < a[i].size()-1; j++){
      st.insert(a[i][j+1]-a[i][j]-1);
    }
    int lo = *(st.rbegin());
    st.erase(st.find(lo));
    lo--;
    
    st.insert(lo/2);
    st.insert((lo+1)/2);
    ans = min(ans, *(st.rbegin()));
  }
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