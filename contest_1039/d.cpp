/**
 *    author: Anicetus_7
 *    created: 2025-07-27 21:22:32
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// void Solve(){
//   int n;
//   cin >> n;
//   vector<int> p(n); for(auto& x: p)cin>>x;

//     int total = 0ll;
//     for(int i = 1; i <= n; ++i){
  
//       total += (n-i+2)* (n - i+1)/2;
//     }

//     for(int i = 0; i< n-1; i++)
//     {
  //       if(p[i] < p[i+1])total -= (i+1)*(n-i-1);
  //     }
  //     cout << total << '\n';
  // }
  
  void Solve(){
    int n;
    cin >> n;
    vector<int> p(n); for(auto& x: p)cin>>x;
    int total = 0ll;
    int sum  =0ll;
    for(int i =1; i<=n; i++){
      total += i*(n-i+1);
    }
    
    for(int i =0; i<n-1; i++){
      if(p[i] <p[i+1]){
        total -= (i+1)*(n-(i+1));
      }
    }
    cout <<total <<endl;
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


const int MAX = 1e5+1;
int tree[MAX];

// Build
void build(int p,int l,int r) {
  if(l==r) tree[p]=a[l];
  else {
    int m=(l+r)/2;
    build(p*2,l,m);
    build(p*2+1,m+1,r);
    tree[p]=min(tree[p*2],tree[p*2+1]);
  }
}
// Query
int query(int p,int l,int r,int ql,int qr) {
  if(ql>r||qr<l) return INF;
  if(ql<=l && r<=qr) return tree[p];
  int m=(l+r)/2;
  return min(query(p*2,l,m,ql,qr),
             query(p*2+1,m+1,r,ql,qr));
}


