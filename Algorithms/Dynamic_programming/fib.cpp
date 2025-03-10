#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &dp){
   if(n <= 1)return n;
   if(dp[n] != -1)return dp[n];
   return dp[n] =  fib(n-1, dp)+ fib(n-2, dp);
}

void solve();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    #endif
    solve();
    
    
    return 0;
}
void solve(){
    int n;
    cin>>n;
    vector<int> dp(3);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <=n; i++){
        dp[i%3] = dp[(i-1)%3] + dp[(i-2)%3];
    }
    cout << dp[n%3];
}