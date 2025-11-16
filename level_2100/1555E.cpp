/**
 *    author: Anicetus_7
 *    created: 2025-10-21 14:00:28
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


const int M = 1e6 + 5;
int seg[4*M];
int lazy[4*M];
 
void updatelazy(int l, int r, int pos){
    seg[pos] += lazy[pos];
    if (l==r){
        lazy[pos] = 0;
        return;
    }
    lazy[pos*2] += lazy[pos];
    lazy[pos*2 + 1] += lazy[pos];
    lazy[pos] = 0;
    return;
}
 
void update(int l, int r, int pos, int ql, int qr, int qval){
    if (lazy[pos]!=0)
    updatelazy(l, r, pos);
    
    if (ql<=l && qr>=r){
        seg[pos]+=qval;
        if (l!=r){
        lazy[pos*2]+=qval;
        lazy[pos*2 + 1] += qval;
        }
        return;
    }
    
    if (ql>r || qr<l)
    return;
    
    int mid = (l+r)/2;
    update(l, mid, pos*2, ql, qr, qval);
    update(mid + 1, r, pos*2 + 1, ql, qr, qval);
    seg[pos] = min(seg[pos * 2] , seg[pos*2 + 1]);
}
 
void print(int l, int r, int pos){
    if (lazy[pos]!=0)updatelazy(l, r, pos);
    cout<<l<<" "<<r<<" "<<seg[pos]<<"\n";
    int mid = (l+r)/2;
    if (l==r) return;
    
    print(l, mid, pos*2);
    print(mid + 1, r, pos*2 + 1);
}

void Solve(){
  int n, m; cin>>n>>m;
  vector<pair<int,pair<int,int>>> a(n);
  for(int i =0; i <n; i++){
    int l,r,w; cin>>l>>r>>w;
    a[i] = {w, {l,r}};
  }
  sort(a.begin(), a.end());

  int r= 0, l = 0; 
  int ans =INF;
  int cnt =0 ;
  while(r< n){
    int left= a[r].second.first;
    int right= a[r].second.second;
    if(left< right){
      update(1, m-1, 1, left, right-1, 1);
    }
    while(seg[1] > 0){
      ans = min(ans, a[r].first- a[l].first);
      int nleft= a[l].second.first;
      int nright= a[l].second.second;
      if(nleft < nright){
        update(1,m-1, 1, a[l].second.first, a[l].second.second-1, -1);
      }
      l++;
    }
    r++;
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
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}





/** 
 * This gives TLE 
 * */ 
// void Solve(){
//   int n,m; cin>>n>>m;
//   vector<int> w(n);
//   vector<vector<int>> seg(n);
//   // vector<vector<int>> adjl(n);
//   for(int i =0 ; i <n ;i++){
//     int l, r; cin>>l>>r;
//     vector<int> segment = {l, r, i};
//     seg[i] = segment;
//     cin>>w[i];
//   }

//   sort(seg.begin(), seg.end(), [](const vector<int>& a, const vector<int>& b){
//     if(a[1] == b[1])return a[0] < b[0];
//     else return a[1] < b[1];
//   });

//   vector<int> weight(n);
//   for(int i =0 ; i <n; i++){
//     auto idx = seg[i][2];
//     weight[i] = w[idx];
//   }

//   auto search = [&](int idx){
//     int low = 0, high = idx-1, ans = -1;
//     while(low <= high){
//       int mid = (low+high)>>1;
//       if(seg[mid][1] >= seg[idx][0]){
//         high = mid -1;
//         ans = mid;
//       }else low= mid +1;
//     }
//     return ans;
//   };

//   int mndiff = 1e9;
//   function<void(int,int,int)> dfs = [&](int node, int mx, int mn)->void{
//     if(seg[node][0] == 1){
//       mndiff = min(mndiff, max(0ll,mx-mn));
//       return;
//     }
//     int pos = search(node);
//     if(pos == -1)return;

//     for(int i = pos; i < node; i++){
//       if(seg[i][1] == seg[node][1])break; // *
//       dfs(i, max(weight[i], mx), min(weight[i], mn));
//     }
//   };

//   // we dfs from m towards 1
//   // no need to traverse those nodes whose r is less than m
//   for(int idx= n-1; idx >= 0; idx--){
//     if(seg[idx][1] < m)break;
//     dfs(idx, weight[idx], weight[idx]);
//   }
//   cout <<mndiff << endl;
// }