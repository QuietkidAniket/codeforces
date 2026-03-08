/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(2005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int dp[MAX][MAX][2];
void Solve(){
    int m,d; cin>>m>>d;
    string a, b; cin>>a>>b;
    function<int(int,int, int,const string&)> f = [&](int ind, int rem, int t,const string& s)->int{
        if(ind == a.size()){
            if(rem == 0)return 1;
            else return 0;
        }
        if(dp[ind][rem][t] != -1)return dp[ind][rem][t];
        int ub =  t ? s[ind] -'0' : 9;
        int sum  = 0;
        for(int digit = 0; digit <= ub; digit++){
            if(ind%2 ==0 && digit == d)continue;
            if(ind%2 !=0 && digit != d)continue;
            int nt  = t && (ub== digit);
            int nrem = (rem*10 + digit)%m;
            sum += f(ind+1, nrem, nt, s);
            sum %= MOD;
        }
        return dp[ind][rem][t] = sum%MOD;
    };
    memset(dp, -1, sizeof dp);
    int u = f(0, 0, 1, b);
    memset(dp, -1, sizeof dp);
    int v = f(0, 0, 1, a);
    
    bool flag = true;
    int r =0;
    for(int i =0 ;i < a.size(); i++){
        if(a[i]-'0' == d && i%2 == 0){
            flag = false;
            break;
        }
        if(a[i]-'0' != d && i%2 != 0){
            flag = false;
            break;
        }
        r = (r*10 +  (a[i]-'0'))%m;
    }
    if(r!= 0)flag= false;
    cout << ((u-v)%MOD + (flag) + MOD)%MOD << endl;
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
