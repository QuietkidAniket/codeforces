#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n;  cin>> n;
  int arr[n];
  for(int i = 0; i< n; i++)
  {
   cin>> arr[i];
  }
  if(arr[n-2] > arr[n-1]){cout << -1<<endl;return;}

  if(arr[n-1] < 0){
    bool flag = false;
    for(int i = 1; i< n; i++)
    {
      if(arr[i] < arr[i-1]){
        flag = true; break;
      }
    }
    if(flag)cout << -1<< endl;
    else cout << 0<< endl;
  }else{
    cout <<  n-2<<endl;
    for(int i = 0; i< n-2; i++)
    {
      cout << i+1 << " "<<  n-1 <<" "<< n << endl;
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
  // cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}