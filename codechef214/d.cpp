/**
 *    author: Anicetus_7
 *    created: 2025-11-26 20:41:42
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,k; cin>>n>>k;
  string s; cin>>s;
  int a[n-1];
  int ptr= 0;
  unordered_map<int,int> idx;
  for(int i =k-2;i >=0; i--){
    idx[ptr] = i;
    a[ptr++] = s[i]-'0';
  }
  for(int i =n-1;i >= k; i--){
    idx[ptr] = i;
    a[ptr++] = (s[i]-'0');
  }


  int l  =0, r = n -2;
  int i = 1;
  int cnt = (s[k-1] == '1');
  vector<int> ans;
  while(l <= r){
    if(i%2==0){
    if(a[l] + a[r] == 0 ){
      ans.push_back(l);
      l++;
    }else if(a[l] == 1 &&  a[r]==0){
      cnt++;
      ans.push_back(l);
      l++;
    }else if(a[l] == 0 &&  a[r]==1){
      cnt++;
      ans.push_back(r);
      r--;
    }else if(a[l] == 1 && a[r] == 1){
      cnt++;
      ans.push_back(l);
      l++;
    }
  }else{
    if(a[l] + a[r] == 0 ){
        ans.push_back(l);
        l++;
      }else if(a[l] == 1 &&  a[r]==0){
        ans.push_back(l);
        l++;
      }else if(a[l] == 0 &&  a[r]==1){
      ans.push_back(r);
      r--;
    }else if(a[l] == 1 && a[r] == 1){
      ans.push_back(l);
      l++;
      cnt--;
    }
    }
    i++;
    if(cnt <=0){
      cout << "-1\n";
      return;
    }
  }
  cout << k << " ";
  for(auto& x : ans){
    cout << idx[x]+1 <<" ";
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