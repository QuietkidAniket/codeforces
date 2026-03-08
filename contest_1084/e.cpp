/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(2e6)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int spf[MAX];
void precompute(){
    for (int i = 2; i< MAX; i++) {
        spf[i] = i;
    }
    for(int i = 2; i*i< MAX; i++){
        if(spf[i] ==i){
            for(int j = i; j < MAX; j+=i)if(spf[j] == j)spf[j] = i;
        }
    }
}


void Solve(){
    int n; cin>>n;
    vector<int> a(n); for(auto& x : a)cin>> x;
    bool flag= true;
    int mx = a[0];
    for(int i =1; i <n ;i++){
        if(a[i-1] > a[i])flag = false;
        mx = max(mx, a[i]); 
    }
    
    if(flag){
        cout <<"Bob\n";
        return;
    }
    flag = false;
    int res = 0;
    vector<int> b(n);
    for(int i = 0 ; i < n; i++){
        int tmp = a[i];
        int p = spf[tmp];
        while(tmp > 1 && tmp%p == 0){ tmp /= p;}
        if(tmp > 1){
            flag = true;
            break;
        }
        b[i] = p;
    }
    if(flag){
        cout << "Alice\n";
        return;
    }
    flag = false;
    for(int i =1;i < n; i++){
        if(b[i-1] > b[i])flag = true;
    }
    if(flag)cout << "Alice\n";
    else cout << "Bob\n";
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  precompute();
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
