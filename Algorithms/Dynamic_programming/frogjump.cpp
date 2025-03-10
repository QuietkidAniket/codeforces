#include <bits/stdc++.h>
using namespace std;

void solve();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    int tt = clock();
    #endif
    solve();
    
    #ifndef ONLINE_JUDGE
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
    #endif
    return 0;
}

int find(int index, int arr[], int dp[]){
    if(index == 0) return 0;
    if(dp[index] != -1)return dp[index];
    int left = find(index -1, arr, dp) + abs(arr[index] - arr[index-1]);
    int right = INT_MAX;
    if(index>1)right = find(index -2, arr, dp) + abs(arr[index] - arr[index-2]);
    return dp[index] =  max(left, right);
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int dp[n+1];
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    cout << find(n-1,arr, dp);
    
}

// sample input
// 6
// 30 10 60 10 60 50
// output : 40