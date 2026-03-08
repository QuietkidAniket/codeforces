/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    int n, x, y; cin>>n>>x>>y;

    vector<int> a(n); for(auto& x : a)cin>> x;

    int mn = min_element(a.begin()+x, a.begin()+y)-a.begin();
    
    vector<int> vec;
    
    for(int i =0 ;i< x; i++)vec.push_back(a[i]);
    for(int i =y;i< n; i++)vec.push_back(a[i]);
    
    vector<int>  ans;
    int j = 0;
    for(j= 0; j < vec.size() && vec[j] < a[mn]; j++){
        ans.push_back(vec[j]);
    }
    
    for(int i =mn; i <y; i++){
        ans.push_back(a[i]);
    }
    for(int i =x; i <mn; i++){
        ans.push_back(a[i]);
    }
    
    for(; j < vec.size(); j++){
        ans.push_back(vec[j]);
    }
    for(auto& x : ans)cout <<x <<" ";
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
