#include <bits/stdc++.h>
using namespace std;

void solve();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    #endif
    solve();
    
    
    return 0;
}
void solve(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; 
        int a[n], b[n+1];

        for(int i = 0; i< n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i< n; i++)
        {
            cin >> b[i];
        }
        b[n]= 0;
        // a -> m, b-> s
        int m =0, s = 0;

        for(int i = 0; i < n ; i++){
            if(a[i] >= b[i+1])
            {
                m += a[i];
                s += b[i+1];
            }
        }
        cout << m -s<< '\n';
    }     
}