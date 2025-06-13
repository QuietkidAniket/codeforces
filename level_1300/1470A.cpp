#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define int ll
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n, m; cin>> n>>m;
  vector<ll> k(n), c(m);
  for(auto& i : k)cin>>i;
  for(auto& i : c)cin>>i;
  sort(k.rbegin(), k.rend());
  multiset<ll> st;
  int left = 0;
  ll cost  =0ll;
  for(int i =0; i < n ;i++){
    int x = k[i] -1;
    while(left <= x){
      st.insert(c[left++]);
    }
    if(st.empty() || (*st.begin()) >= c[x]){
      cost += c[x];
    }else{
      ll smallestelem = *st.begin();
      st.erase(st.find(smallestelem));
      cost += smallestelem;
    }
  }
  cout << cost;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  int tt = clock();
  #endif
  
  int t = 1;
  if(multi)cin>> t;
  while(t--){
  Solve();
  cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}