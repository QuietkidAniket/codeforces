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
    int n; cin>>n;
    vector<int> a(n);
    vector<int> c(n+1,0);
    for(auto& x : a)cin>> x;

    int pivot = -1;
    int cnt =0;
    for(int i =0 ;i<n;i++){
        if(pivot < a[i]){
            if(i == 0){
                cnt++;
                pivot = a[i];
            }else if(a[i-1] <= a[i] && a[i-1] +1 == a[i] || a[i-1] ==a[i]){ // increasing by +1 only
            }else if(a[i-1] > a[i]){ // decreasing by any amount
            }else{ cnt++; pivot = a[i];}
        }else{
            pivot = a[i];
            cnt++;
        }
        c[i+1] = cnt;
        // cout << i << " : " << pivot << endl;
    }
    // cout << cnt << endl;
    vector<int> pref(n+1,0);
    map<int,int> mp;
    int sum = 0;
    for(int i =0 ;i < n; i++){
        pref[i+1]=  pref[i] + c[i+1];
        sum += (i+1)*c[i+1] - pref[i+1] + i+1;
        if(i!=0 && a[i] < a[i-1] && c[i+1] == c[i])sum += (mp[a[i]]-(i+1))*(mp[a[i]]-(i+1)+1)/2;
        mp[a[i]] = i+1;
    }
    cout <<sum<<endl;
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
