/**
 *    author: Anicetus_7
 *    created: 2025-12-23 15:55:59
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// const int N = 2e5 + 7;
// int seg[4 * N], lz[4 * N];
// // range add, find first < 0 
 
// void build(int l, int r, int pos){
//     lz[pos] = 0;
//     if (l == r){
//         seg[pos] = l;
//         return;
//     }
//     int mid = (l + r) / 2;
//     build(l, mid, pos * 2);
//     build(mid + 1, r, pos * 2 + 1);
    
// //    cout << "BUILDING " << l << " " << r << " " << pos << "\n";
    
//     seg[pos] = min(seg[pos * 2], seg[pos * 2 + 1]);
//  //   cout << seg[pos] << "\n";
// }
 
// void updlz(int l, int r, int pos){
//     seg[pos] += lz[pos];
//     if (l != r){
//         lz[pos * 2] += lz[pos];
//         lz[pos * 2 + 1] += lz[pos];
//     }
//     lz[pos] = 0;
// }
 
// void upd(int l, int r, int pos, int ql, int qr, int x){
//     updlz(l, r, pos);
//     if (l >= ql && r <= qr){
//         lz[pos] += x;
//         updlz(l, r, pos);
//     } else if (l > qr || r < ql){
        
//     } else {
//         int mid = (l + r) / 2;
//         upd(l, mid, pos * 2, ql, qr, x);
//         upd(mid + 1, r, pos * 2 + 1, ql, qr, x);
//         seg[pos] = min(seg[pos * 2], seg[pos * 2 + 1]);
//     }
    
//     // cout << "UPDATED " << l << " " << r << " " << pos << " " << seg[pos] << "\n";
// }
 
// int query(int l, int r, int pos, int ql, int qr){
//     updlz(l, r, pos);
//     if (l >= ql && r <= qr){
//         return seg[pos];
//     } else if (l > qr || r < ql){
//         return INF;
//     }
    
//     int mid = (l + r) / 2;
//     return min(query(l, mid, pos * 2, ql, qr), query(mid + 1, r, pos * 2 + 1, ql, qr));
// }

const int N = 2e5 + 7;
long long seg[4 * N], lz[4 * N];

// range add, range sum

void build(int l, int r, int pos){
    lz[pos] = 0;
    if (l == r){
        seg[pos] = 0;   // same initialization
        return;
    }

    int mid = (l + r) / 2;
    build(l, mid, pos * 2);
    build(mid + 1, r, pos * 2 + 1);

    seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
}

void updlz(int l, int r, int pos){
    if (lz[pos] == 0) return;

    seg[pos] += lz[pos] * (r - l + 1);

    if (l != r){
        lz[pos * 2]     += lz[pos];
        lz[pos * 2 + 1] += lz[pos];
    }
    lz[pos] = 0;
}

void upd(int l, int r, int pos, int ql, int qr, int x){
    updlz(l, r, pos);

    if (l > qr || r < ql) return;

    if (l >= ql && r <= qr){
        lz[pos] += x;
        updlz(l, r, pos);
        return;
    }

    int mid = (l + r) / 2;
    upd(l, mid, pos * 2, ql, qr, x);
    upd(mid + 1, r, pos * 2 + 1, ql, qr, x);

    seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
}

long long query(int l, int r, int pos, int ql, int qr){
    updlz(l, r, pos);

    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return seg[pos];

    int mid = (l + r) / 2;
    return query(l, mid, pos * 2, ql, qr)
         + query(mid + 1, r, pos * 2 + 1, ql, qr);
}

void Solve(){
  int n; cin>>n;
  vector<int> a(n+1);
  for(int i =1; i<= n; i++)cin>>a[i];
  build(1, n, 1);
  for(int i =0;i < n; i++){
    int idx; cin>>idx;
    int offset = query(1, n, 1, idx, idx);
    // cout<< offset<<endl;
    cout << a[idx+offset] <<" ";
    upd(1,n,1, idx, n,1);
  } 
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