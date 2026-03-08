/**
 *    author: Anicetus_7
 *    created: 2026-01-25 21:18:41
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define fi first
#define si second

void Solve(){
  int n; cin>>n;
  int ax, ay, bx, by; cin>>ax>>ay>> bx>>by;

  vector<int> a_x(n), a_y(n);
  for(auto& x : a_x)cin>> x;
  for(auto& x : a_y)cin>> x;

  vector<pair<int,int>> a(n);
  for(int i = 0 ;i < n ; i++){
    a[i] = {a_x[i], a_y[i]};
  }
  a.push_back({ax, ay});
  a.push_back({bx, by});

  sort(a.begin(), a.end());
  map<int, vector<int>> mp; // xi -> {yi1, yi2, ...  } smaller to greater
  for(int i = 0 ;i < n+2; i++){
    mp[a[i].fi].push_back(a[i].si); 
  }

  auto manhattan = [&](pair<int,int>& p, pair<int,int>& q){
    return abs(p.fi - q.fi) + abs(p.si - q.si);
  };

  int ans= 0;
  // int prev_y = ay;
  // int prev_x = ax;
  // for(auto [x, vec] :  mp){
  //   pair<int,int> prev_ =  {prev_x, prev_y};
  //   if(vec.front() >= prev_y){ 
  //     pair<int,int> g= {x, vec.front()};
  //     int sum = manhattan(prev_, g);
  //     for(int i =1; i < vec.size(); i++){
  //       sum += abs(vec[i]- vec[i-1]);
  //     }
  //     ans+= sum;
  //     prev_y = vec.back();
  //   }else if(vec.back() <= prev_y){
  //     pair<int,int> g= {x, vec.back()};
  //     int sum = manhattan(prev_, g);
  //     for(int i = vec.size()-2; i >=0; i--){
  //       sum += abs(vec[i+1]- vec[i]);
  //     }
  //     ans+= sum;
  //     prev_y = vec.front();
  //   }else{
  //     if(abs(prev_y - vec.front()) <  abs(prev_y - vec.back())){
  //       pair<int,int> g= {x, vec.front()};
  //       int sum = manhattan(prev_, g);
  //       for(int i =1; i < vec.size(); i++){
  //         sum += abs(vec[i]- vec[i-1]);
  //       }
  //       ans+= sum;
  //       prev_y = vec.back();
  //     }else{
  //       pair<int,int> g= {x, vec.back()};
  //       int sum = manhattan(prev_, g);
  //       for(int i = vec.size()-2; i >=0; i--){
  //         sum += abs(vec[i+1]- vec[i]);
  //       }
  //       ans+= sum;
  //       prev_y = vec.front();
  //     }
  //   }
  //   prev_x= x;
  // }

  int mn = 0, mx = 0; 
  auto it = mp.begin();
  int px = it->first;
  int pmn = it->second[0], pmx = it->second.back(); 
  it++; 

  for(; it != mp.end(); ++it){
    int cx = it->first;
    vector<int>& v = it->second;
    int cmn = v.front(), cmx = v.back();
    int base = (cx - px) + (cmx - cmn); 
    
    // To end at bottom, enter at top 
    int n_mn = min(mn + abs(pmn - cmx), mx + abs(pmx - cmx)) + base;
    
    // To end at top , enter at bottom
    int n_mx = min(mn +abs(pmn - cmn), mx+abs(pmx - cmn)) + base;

    mn = n_mn, mx = n_mx;
    px = cx, pmn = cmn, pmx = cmx;
  }
  ans = min(mn, mx);

  cout << ans<< endl;
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