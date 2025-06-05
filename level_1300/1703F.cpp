#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

// Fastest Greedy solution
// int x[1<<18];
// void Solve(){
//   int n; cin >> n;
//   ll ans = 0;
//   for(int i = 1; i<= n; i++)
//   {
//     int a = 0;
//     cin>> a;
//     x[i] = x[i-1];
//     if(a < i){
//       x[i]++;
//       ans += x[a-1];
//     }
//   } 
//   cout <<ans;
// }

// Range sum Segment Tree alternative v
struct segtree{
  vector<int>tree;
  int sz;
  void init(int n){
    sz=1;
    sz<<= (int)(log2(n)+1);
    tree.assign(sz*2-1,0);
  }
  void set(int x,int lx,int rx,int i,int v){
    if(rx-lx==1){tree[x]+=v;return;}
    int m=(lx+rx)/2;
    if(i<m)set(x*2+1,lx,m,i,v);
    else set(x*2+2,m,rx,i,v);
    tree[x]=tree[x*2+1]+tree[x*2+2];
  }
  void set(int i,int v){
    set(0,0,sz,i,v);
  }
  int get(int x,int lx,int rx,int l,int r){
    if(r<=lx || rx<=l)return 0;
    if(l<=lx && r>=rx)return tree[x];
    int m=(lx+rx)/2;
    return get(x*2+1,lx,m,l,r)+get(x*2+2,m,rx,l,r);
  }
  int get(int l,int r){
    return get(0,0,sz,l,r);
  }
};

void Solve(){
  int n; cin>>n;
  vector<pair<int,int>> arr;
  for(int i =1; i <= n;i++){
    int a;cin>> a; 
    if(a < i){
      arr.push_back({a, i});
    }
  }
  // sort in ascending order the number, index} pairs
  sort(arr.begin(), arr.end());
  segtree sgt;
  sgt.init(n+3);
  ll res = 0;
  for(int i = 0; i < arr.size(); i++){
    // map the index value and set node value to 1
    sgt.set(arr[i].second,1); 
    // (actually) get the number of indices i or arr[i].second < arr[j].first
    // by getting the sum of the numbers from index 1 till arr[i].first 
    res += sgt.get(1, arr[i].first);
  }
  cout << res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
  freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
  int tt = clock();
  #endif
  
  int t = 1;
  if(multi)cin>> t;
  while(t--){
  Solve();
  cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}