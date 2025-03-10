#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int pfx[n+1];
    pfx[0] = 0;
    for(int i = 0; i< n; i++)
    {   
        cin >> arr[i];
        pfx[i+1]=  pfx[i]+arr[i];
    }   

    for(int i = 0; i<= n; i++)
    {
        cout << pfx[i] << ", "; 
    }
    cout << '\n';

    
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    solve();
    
    
    return 0;
}