/**
 *    author: Anicetus_7
 *    created: 2025-10-17 19:02:39
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(1001)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

static bool flag = false;
static int32_t ops[MAX];
static void generate(){
  if(flag)return;
  flag = true;
  memset(ops, 0, sizeof ops);
  for(int32_t i = 0; i< MAX; i++)ops[i]=  i-1;
  for(int32_t i =1; i  < MAX;  i++){
    for(int32_t j = i; j >= 1; j--){
      int t = i + i/j;
      if(t >= MAX)break;
      ops[t] = min(ops[i]+1, ops[t]);
    }
  }
}

void Solve(){
  int n,k; cin>>n>>k;

  vector<int> b(n);for(auto& x : b)cin>> x;
  vector<int> c(n);for(auto& x : c)cin>> x;
  int sum =0;
  for(int i =0 ; i <n ;i++){
    sum += ops[b[i]];
  } 
  if(sum < k){
    cout << accumulate(c.begin(), c.end(), 0ll) << endl;
    return;
  }
  vector<int> dp(k+1,0);
  for(int i =0; i <n; i++){ // iterate through the items
    for(int capacity = k; capacity >=ops[b[i]]; capacity--){ 
      dp[capacity] = max(dp[capacity-ops[b[i]]] + c[i], dp[capacity]);
    }
  }
  cout << *max_element(dp.begin(), dp.end())<<endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  generate();
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