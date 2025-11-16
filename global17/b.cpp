  /**
   *    author: Anicetus_7
   *    created: 2025-10-21 00:53:34
  **/
  #include <bits/stdc++.h>
  using namespace std;
  #define int long long
  #define INF (int)1e18
  #define MOD (int)(1e9 + 7)
  #define MAX (int)(20005)
  mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

  void Solve(){
    int n; cin>>n;

    vector<int> a(n);
    for(auto& x : a)cin>> x;
    if(a == vector<int>(a.rbegin(), a.rend())){
      cout << "YES\n";
      return;
    }

    auto test = [&](int x){
      vector<int> b;
      for(int i = 0 ;i <n; i++){
        if(a[i] != x)b.push_back(a[i]);
      }
      return b == vector<int>(b.rbegin(), b.rend());
    };

    for(int i =0 ;i <n; i++){
      if(a[i] != a[n-1-i]){
        if(test(a[i]) || test(a[n-1-i])){
          cout << "YES\n";
        }else cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
    
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