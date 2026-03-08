/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(18)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

pair<int,int> dp[MAX][2]; // {sum, count of numbers}

void reset(){
    for(int i = 0;i < MAX ; i++){
        for(int j =0; j < 2; j++)dp[i][j]= {-1ll,-1ll};
    }
}
void Solve(){
    int a, b; cin>>a>>b;
    string c = to_string(max(a-1,0ll));
    string d = to_string(b);
    while(d.size() != c.size())c = "0" +c;
    
    function<pair<int,int>(int,int,const string&)> f = [&](int ind, int t, const string& s)->pair<int,int>{
        if(ind == s.size())return {0ll, 1ll};
        if(dp[ind][t] != make_pair(-1ll, -1ll))return dp[ind][t];
        int ub = t? s[ind] - '0' :  9;
        int sum = 0, cnt = 0;
        for(int d = 0; d <= ub; d++){
            int nt = t&&(d == ub);
            auto p = f(ind+1, nt, s);
            sum += p.first +  p.second*d;
            cnt += p.second;
        }
        return dp[ind][t] = {sum, cnt};
    };
    
    reset();
    int res = f(0, 1, d).first;
    reset();
    res -= f(0, 1, c).first;
    cout << res <<endl;
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
