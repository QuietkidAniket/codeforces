/**
 *    author: Anicetus_7
 *    created: 2025-09-18 16:39:53
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

class Project{
  public:
  int start, end, points;
  Project(): start(0), end(0), points(0){}
  Project(int s, int e, int p): start(s), end(e), points(p) {}
  bool operator<(const Project& other){
    if(this->end == other.end){
      return this-> start < other.start;
    }else return this->end < other.end;
  }
};


void Solve(){
  int n; cin>>n;

  vector<Project> a(n);

  for(int i = 0 ; i < n; i++){
    int s,e, p; cin>>s>>e>>p;
    a[i] =Project(s,e,p);
  }
  sort(a.begin(), a.end());
  vector<int> ends(n);
  for(int i =0 ; i < n; i++){
    ends[i] = a[i].end;
  }

  int dp[n+1];
  memset(dp, 0, sizeof dp);

  auto bin = [&](int target){
    int low = 0, high = n-1, ans = -1;
    while(low <= high){
      int mid = (low + high)>>1;
      if(ends[mid] < target){
        ans = mid;
        low= mid +1;
      }else high  =mid -1;
    } 
    return ans;
  };

  for(int i = 1; i <= n; i++){ 
    int pos = bin(a[i-1].start);
    dp[i] = a[i-1].points + dp[pos+1];
    dp[i] = max(dp[i-1], dp[i]);
  }
  cout << dp[n]<< endl;
  
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
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}