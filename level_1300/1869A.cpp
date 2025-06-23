/**
 *    author:  Anicetus_7
 *    created: 2025-06-17 12:10:02
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n);
  for(int i = 0; i< n; i++)
  {
    cin >> a[i];
  }

  int cnt[32];
  
  for(int l = 0 ; l < 31; l++){ 
    for(int i = 0; i < n; i++){
      if((a[i] &(1<<l)) != 0)cnt[l]++;
    }
  }
  bool isodd = false;
  for(int l = 0; l < 31; l++){
    if(cnt[l] & 1){
      isodd = true;
      break;
    }
  }
  if(isodd){
    if(n&1)cout<< 4 << endl;
    else cout << 2 << endl;
  }else{
    cout << 1 << endl;
  }
  cout<< 1<< " "<< n<<endl;
  if(isodd){
    if(n&1){
      cout<< 1 << " " << n-1<< endl;
      cout<< n-1 << " " << n << endl;
      cout<< n-1 << " " << n << endl;
    }else{
      cout<< 1 << " " << n<< endl;
    }
  }
  
}
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  int tt = clock();
  #endif
  
  int t = 1;
  cin>> t;
  while(t--){
  Solve();
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}