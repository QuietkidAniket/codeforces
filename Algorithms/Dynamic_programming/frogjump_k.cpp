#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    int  dp[n];
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int minSteps = INT_MAX;
        for(int j =1; j <= k; j++){
            if(i >= j){
                int jump = dp[i-j]+ abs(arr[i] - arr[i-j]);
                minSteps = min(minSteps, jump);
            }
            dp[i] = minSteps;
        }
    }
    cout <<  dp[n-1];

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    auto begin = std::chrono::high_resolution_clock::now();
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    int tt = clock();
    #endif
    
    int t;
    cin>> t;
    while(t--)
    Solve();
    cout << '\n';
    
    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}