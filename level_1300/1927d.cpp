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
  // pr[i] stores the largest index j where arr[j] != arr[i]
  vector<int> pr(n);
  for(int i = 0; i< n; i++)
  {
    cin >> arr[i];
    if(i > 0 && arr[i] == arr[i-1]){
      pr[i] = pr[i-1];
    }else pr[i]= i-1;
  }
  int q; cin>> q;
  for(int query = 0; query < q; query++){
    int l, r;
    cin >> l >> r;
    l--, r--;
    if(l > pr[r]){
      cout << -1 << " " << -1 << '\n';
    }else{
      cout << pr[r] +1 << " " << r+1 <<endl;
    }
  }
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