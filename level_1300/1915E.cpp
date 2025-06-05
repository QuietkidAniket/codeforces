#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n; cin>> n;
  int arr[n];
  set<ll> st;
  ll odd = 0ll, even = 0ll;
  st.insert(0ll);
  bool flag = false;

  for(int i = 0; i< n; i++)
  {
    cin>> arr[i];
  }

  for(int i = 0; i< n; i++)
  {
    ll x = (ll)arr[i];
    if(i%2 == 0)even += x;
    else odd += x;

    if(st.find(odd - even) != st.end()){
      cout << "YES";
      flag = true;
      break;
    }
    st.insert(odd- even);
  }

  if(!flag)cout << "NO";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
  freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
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