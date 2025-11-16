/**
 *    author: Anicetus_7
 *    created: 2025-10-22 18:56:28
**/
#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int32_t>> divs(MAX+1);

void generate(){    
    for(int i =2; i <= MAX; i++){
        for(int j = i; j <= MAX; j += i){
            divs[j].push_back(i);
        } 
    }
}

void Solve(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i =1; i <= n; i++)cin>>a[i];
    vector<int> cnt(n+1,0);

    int ans = 0;
    int g= 0;
    int ptr =n;
    for(int i = 1; i <= n; i++){
        g = __gcd(g, a[i]);
        for(auto num :  divs[a[i]]){
            cnt[num]++;
            if(num > g){
                ans= max(ans, cnt[num]);
            }
        }
        while(ptr > g){
            ans = max(ans, cnt[ptr]);
            ptr--;
        }
        cout << ans << " ";
    }
    cout << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  generate();
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