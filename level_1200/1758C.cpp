/**
 *    author: Anicetus_7
 *    created: 2025-08-30 11:27:29
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,x; cin>>n>>x;

  if(n%x != 0){
    cout << -1 << endl;
    return;
  }

  int a[n+1];
  
  iota(a, a+n+1, 0ll);

  a[1]=x, a[n] = 1;

  // store all factors of n which are multiples of x

  vector<int> factors;
  for(int i = x; i <= n; i += x){
    if(n%i == 0){
      factors.push_back(i);
      x = i;
    }
  }

  for(int i = 0; i< factors.size()-1; i++)
  {
    a[factors[i]] = factors[i+1];
  }

  for(int i = 1; i<= n; i++)
  {
    cout << a[i] << " ";
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