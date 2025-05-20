#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n;cin>> n;
  int gang_2 = 0;
  vector<int> arr(n+1);
  arr[0] = 0;
  for(int i = 1; i <= n; i++){
    int x; cin>>  x;
    arr[i] = x;
    if(i > 1 && arr[i] != arr[1]){ 
      gang_2 = i;
    }
  }
  if(arr[gang_2] == 0){
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  // connect gang1 to other districts
  for(int i = 2; i <= n; i++){
    if(arr[i] == arr[1])continue;
    cout << 1 <<" " << i <<endl;
  }
  // connect remaining gang1 districts to one district of some other gang
  for(int i = 2; i<= n; i++)
  {
    if(arr[i] == arr[1])cout << gang_2 << " "<< i << endl;
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
  // cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}