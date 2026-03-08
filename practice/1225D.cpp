/**
 *    author: Anicetus_7
 *    created: 2026-01-11 23:31:02
**/
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vector<int> sieve((int)1e5+1,1); // 1 -> prime, 0 -> non prime
vector<int> primes;
int z;
void generate(){
  sieve[1] = 0;
  for(int i =2; i*i<= (int)1e5; i++){
    if(sieve[i]){
      for(int j = i*i; j <=(int)1e5; j+=i)sieve[j] = 0;
    }
  }
  for(int i =2 ;i <= (int)1e5; i++)if(sieve[i])primes.push_back(i);
  z= primes.size();
}
void Solve(){
  int n; cin>>n;
  int k; cin>>k;

  map<vector<pair<int,int>>, long long> mp;
  long long cnt =0;
  for(int i =0;i<n; i++){
    vector<pair<int,int>> prime_degrees,complementary;
    int num, x; cin>>num;
    int copy =  num;
    // iterating through the primes
    for(int j =0 ; j <z;j++){
      int prime = primes[j];
      if(prime*prime > copy) break;
      int deg=0;
      if(copy % prime == 0){
        while(copy%prime == 0){ 
          copy /= prime;   
          deg++;
        }
        deg %= k;
        if(deg){
          prime_degrees.push_back({prime, deg});
          complementary.push_back({prime, (k- deg)%k});
        }
      }
    }
    if(copy > 1){
      int deg= 1;
      deg %= k;
      prime_degrees.push_back({copy, deg});
      complementary.push_back({copy, (k- deg)%k});
    }
    sort(prime_degrees.begin(), prime_degrees.end());
    sort(complementary.begin(), complementary.end());
    cnt += mp[complementary];
    mp[prime_degrees]++;
  }
  cout << cnt << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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