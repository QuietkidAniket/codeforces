/**
 *    author: Anicetus_7
 *    created: 2025-12-29 16:34:00
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(1e5+1)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

static int sieve[MAX];// 0 -> prime, 1-> non-prime
static bool flag = false;
static void generate(){
  if(flag)return;
  sieve[1] = 1;
  for(int i =2;i*i <MAX;i++){
    if(!sieve[i]){
      for(int j =i; j<MAX; j+=i )sieve[j] = 1;
    }
  }
  flag = true;
}

void Solve(){
  int n; cin>>n;
  vector<int> heap(n);
  for(auto& x : heap)cin>> x;
  static map<int,int> cache;
  function<int(int)> nimber = [&](int num)->int{
    if(num == 1)return -1;
    if(cache.count(num))return cache[num];
    unordered_set<int> st;
    for(int i = 2; i*i<= num; i++){
      if(sieve[i])continue;
      int res= num;
      while(res%i == 0){
        st.insert(nimber(res));
        res /= i;
      }
    }
    int mex = 0;
    while(st.count(mex))mex++;
    return cache[num] = mex;
  };

  int xor_sum =0;
  for(int i =0 ;i < n ; i++){
    xor_sum ^= nimber(heap[i]);
  }
  if(xor_sum)cout << "Mojtaba" <<endl;
  else cout << "Arpa" << endl;
  
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