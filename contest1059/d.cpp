/**
 *    author: Anicetus_7
 *    created: 2025-10-17 21:38:47
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;

  int cnt =0;

  cout << "2 1 " << n <<endl;
  cout.flush();

  cin>> cnt;
  cout << "1 1 " << n <<endl;
  cout.flush();

  int x; cin>>x;
  cnt -= x;

  int low =1, high =n;
  int l =1, r =n;
  // find left bound
  while(low <= high){
    int mid = (low+high)>>1;
    cout << "2 " << low << " " << mid<<endl;
    cout.flush();

    int cur= 0;
    cin>>cur;

    cout << "1 " << low << " " << mid<<endl;  
    cout.flush();
    int x; cin>>x;
    cur -=x;

    if(cur  == 0){
      low = mid+1;
    }else{
      high =mid -1;
    }
  }
  cout << "! " << low << " " << low + cnt-1 <<endl; 
  cout.flush();
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