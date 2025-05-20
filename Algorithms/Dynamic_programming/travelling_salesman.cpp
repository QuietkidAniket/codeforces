#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
#define vec vector
static const int mod = 1e9 + 7;

vec<vec<int>> dp;

int tsp(int mask, int curr, int n,const vec<vec<int>>& cost){
  // base case
  if(mask == ((1<<n)-1)){
    return cost[curr][0]; // cost of returning to the starting city
  }
  if(dp[curr][mask] != -1)return dp[curr][mask];

  int ans = INT_MAX;
  for(int i = 0; i< n; i++)
  {
    if((mask & (1 << i)) == 0){ // if ith city not visited yet
      // mark the city as visited and visit the city
      ans = min(ans, cost[curr][i]  + tsp((mask | (1 << i)), i, n, cost));
    }
  }
  return dp[curr][mask] = ans;
}

int main() { // sample input
  
  vector<vector<int>> cost = {{0, 10, 15, 20}, 
                              {10, 0, 35, 25}, 
                              {15, 35, 0, 30}, 
                              {20, 25, 30, 0}};

  int n = cost.size();
  dp.resize(n, vec<int>(1<<n, -1));
  int res = tsp(1,0, n, cost);
  cout << res << endl;
  return 0;
}  