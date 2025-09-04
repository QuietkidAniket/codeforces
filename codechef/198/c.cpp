/**
 *    author: Anicetus_7
 *    created: 2025-08-06 20:49:46
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

class MEX{
  public:
    set<int> missing;
    unordered_map<int, int> freq;

    void init_mex(int limit) {
        missing.clear(); freq.clear();
        for (int i = 0; i <= limit; ++i) missing.insert(i);
    }

    void build(const vector<int>& a){
      int n = a.size();
      for(int i = 0; i< n; i++)
      {
        add(a[i]);
      }
    }

    void add(int x) {
        freq[x]++;
        if (missing.count(x)) missing.erase(x);
    }

    void remove(int x) {
        if (--freq[x] == 0) missing.insert(x);
    }

    int get_mex() {
        return *missing.begin();
    }
};


void Solve(){
  int n; cin>> n;
  vector<int> a(n); for(auto& x : a)cin>>x;
  vector<int> b(n); for(auto& x : b)cin>>x;
  
  MEX x;
  x.init_mex(n);
  MEX y;
  y.init_mex(n);
  x.build(a);
  y.build(b);

  int ans = max(x.get_mex(), y.get_mex());

  for(int i = 0; i< n; i++)
  {

    if(y.missing.count(a[i]-1) == 0 && x.missing.count(b[i]-1) == 0){
      x.remove(a[i]);
      y.remove(b[i]);
      x.add(b[i]);
      y.add(a[i]);

      if(max(x.get_mex(), y.get_mex()) <= ans){
        ans = max(x.get_mex(), y.get_mex());
      }else{
        x.remove(b[i]);
        y.remove(a[i]);
        x.add(a[i]);
        y.add(b[i]);
      }
    }
  }
  cout << ans << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}