/**
 *    author: Anicetus_7
 *    created: 2025-10-24 21:49:28
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> idx;
  for(int i =1; i<= n; i++)idx.push_back(i);

  vector<int> rem = idx;

  idx.pop_back();

  for(int bit = 0; bit < 15 ; bit++){
    vector<int> ones, zeros;
    for(int i =0;i < idx.size(); i++){
      cout << "? " << idx[i] << " " << (1<<bit) << endl;
      cout.flush();
      int x;cin>>x; if(x == 0)zeros.push_back(idx[i]);else ones.push_back(idx[i]);
    }

    // iterate through all the elements in remaining set
    // and count the number of 0's and 1's in current bit
    // then decide which subset to focus on if expected count is not met
    int on = 0, ze = 0;
    for(int i = 0; i < rem.size(); i++){
      if(rem[i]&(1<<bit)){
        on++;
      }else ze++;
    }
    vector<int> cur;
    if(ones.size() != on){
      for(int i = 0; i < rem.size(); i++){
        if(rem[i] &(1<<bit)){
          cur.push_back(rem[i]);
        }
      }
      idx = ones;
    }else if(zeros.size() != ze){
      for(int i = 0; i < rem.size(); i++){
        if((rem[i] & (1<<bit)) == 0){
          cur.push_back(rem[i]);
        }
      }
      idx =zeros;
    }else{
      cout << "Fallback ! ... ";// This should not happen theoretically
      return;
    }
    rem = cur;
    if(rem.size() <= 1)break;
  }
  cout << "! " << rem[0]<< endl;
  cout.flush(); 
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}