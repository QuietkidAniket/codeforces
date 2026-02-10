/**
 * author: Anicetus_7
 * created: 2026-01-23 15:02:01
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

/*
 *  if 0th index has a0 then we iterate freely from a1 to 9
 *  dp[i][prev][tight] = count of integers till ith index given that at ith index the digit is prev
 *  and the previous index doesnt have prev as the digit;
 *  once tight, all the upcoming indices are tight
*/

string str;
int dp[20][11][2];
int n;


int modPow(int base, int exp) {
  int res = 1;
  while (exp > 0) {
      if (exp & 1ll) res = (res * base);
      base = (base * base);
      exp >>= 1ll;
  }
  return res;
}

int f(int ind, int prev, int t){
   if(ind  == n )return 1;
   if(dp[ind][prev][t] != -1)return dp[ind][prev][t];
   int ub = t? str[ind] - '0' : 9;

   int sum  =0;
   for(int digit = 0; digit <= ub; digit++){
        if(digit == prev)continue;
        if(ind == 0 && n > 1 && digit == 0)continue; // 1st digit cannot be 0 in number having more than 1 digits
        int new_tight = (t && (digit==ub));
        sum += f(ind+1, digit, new_tight);
   }
   return dp[ind][prev][t] = sum;
}
bool check(string& a){
    for(int i =1;i< a.size(); i++){
        if(a[i] == a[i-1])return false;
    }
    return true;
}

int g(const string a){
    n = a.size();
    str = a;
    int sum = 0;
    for(int len = 1; len < n; len++){
       if(len == 1) sum += 10;
       else sum +=  9* modPow(9, len-1);
    }
    memset(dp, -1, sizeof dp);
    sum += f(0, 10, 1);
    return sum;
}
void Solve(){
    string a, b;
    cin>>a>>b;
    cout << g(b)- g(a) + check(a)<< endl;
}


//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
//  cin >> t;
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

