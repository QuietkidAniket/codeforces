/**
 *    author: Anicetus_7
 *    created: 2026-01-14 09:54:06
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int a, b,c; cin>>a>>b>>c;

  int m; cin>>m;
  vector<int> usb;
  vector<int> ps2;
  for(int i = 0;i <m;i++){
    int val; string c;
    cin>>val>>c;
    if(c== "USB"){
      usb.push_back(val);
    }else{
      ps2.push_back(val);
    }
  }

  sort(usb.begin(), usb.end());
  sort(ps2.begin(), ps2.end());
  int res = 0;
  int i =0 , j=0 ;
  int cnt =0 ;
  for(; i < min(a, (int)usb.size()); i++, cnt++)res+= usb[i];
  for(; j < min(b, (int)ps2.size()); j++, cnt++)res+= ps2[j];

  vector<int> z(usb.begin()+i, usb.end());
  z.insert(z.end(),ps2.begin()+j, ps2.end());
  
  sort(z.begin(), z.end());
  int ptr = 0;
  while(ptr < min((int)z.size(),c)){
    res += z[ptr];
    cnt++;
    ptr++;
  }
  cout << cnt << " " <<res << endl;

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