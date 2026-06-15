  /**
   *    author: Anicetus_7
   *    created: 2026-06-09 20:47:10
  **/
  #include <bits/stdc++.h>
  #ifndef ONLINE_JUDGE
  #include <bits/debug.h>
  #else
  #define DEBUG(x) 42 
  #endif
  using namespace std;
  #define int long long
  #define INF (int)1e18
  #define MOD (int)(1e9 + 7)
  #define MAX (int)(200005)
  mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

  void Solve(){
    int n,k; cin>>n>>k;
    
    string s; cin>>s;

    vector<int> open, close;
    for(int i =0 ; i <n; i++){
      if(s[i] == '(')open.push_back(i);
      else close.push_back(i);
    }

    // vector<int> cnto(n+1, 0), cntc(n+1,0);

    // for(int i =0 ;i <n; i++){
    //   cnto[i+1] = cnto[i];
    //   cntc[i+1] = cntc[i];
    //   if(s[i] == '(')cnto[i+1] += 1;
    //   else cntc[i+1] += 1;
    // }

    // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    // for(int i=0 ;i<n; i++){
    //   if(s[i] == '('){
    //     pq.push({cntc[n]-cntc[i],i});
    //   }else pq.push({cnto[i+1]-cnto[0],i});
    // }
    // while(k>0){
      //   auto [rem, idx] = pq.top();
      //   pq.pop();
      //   if(rem>k || rem == 0)break;
      //   ans[idx]= 1;
      //   k-=rem;
      // }
      
      vector<int> ans(n,0);
    int res = INF, bo = 0, so = open.size(), sc = close.size();

    for(int o = max(0ll, k-sc); o <= min(k, so); o++){
      int c= k-o, cnt = 0, pair= 0 ;
      if(o < so && c < sc){
        for(int i = open[o] ; i <= close[sc-(c+1)]; i++){
          if(s[i] == '(')cnt++;
          else if(cnt> 0) cnt--, pair++;
        }
      }
      if(pair < res)res =  pair, bo = o;
    }
    for(int i =0 ;i < bo; i++)ans[open[i]] = 1;
    for(int i =0; i <k - bo; i++)ans[close[sc-(i+1)]] = 1;
    for(int i =0;i <n; i++){
      cout << ans[i];
    }
    cout << endl;
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