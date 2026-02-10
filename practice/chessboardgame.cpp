/**
 *    author: Anicetus_7
 *    created: 2025-12-29 14:20:01
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int BOARD_LEN = 15ll;
/**
 * @return The nimber value of a coin at a single position
 * assuming that a coin is a single subgame
 */
int nimber(int r, int c){
  static map<pair<int,int>,int> cache;
  if(cache.count({r,c}))return cache[{r,c}];
  if(r < 1 || c <1 || r > BOARD_LEN || c > BOARD_LEN)return -1;

  set<int> st{
    nimber(r-2, c+1),  
    nimber(r-2, c-1),  
    nimber(r+1, c-2),  
    nimber(r-1, c-2),  
  };

  int mex = 0;
  while(st.count(mex))mex++;
  return cache[{r,c}] =  mex;
}

void Solve(){
  int k ; cin>>k;
  int xor_sum = 0;
  for(int i =0; i <k; i++){
    int x,y; cin>>x>>y;
    xor_sum ^= nimber(x,y);
  }
  if(xor_sum)cout << "First\n";
  else cout << "Second\n";
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