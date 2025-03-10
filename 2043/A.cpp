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
    int tt = clock();
    #endif
    solve();
    
    #ifndef ONLINE_JUDGEJUDGE
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
    #endif
    return 0;
}
void solve(){
    int t;
    cin>>t;
    while(t--){
        long long n =0ll;
        cin>> n;
        long long i;
        long long ans= 0ll;
        long long fact = 1;

        if(n <= 3){cout<<1<<'\n';continue;}

        for(i = 1ll; n > 3 ; i++, n/=2){
            fact = pow(2,i);
            ans = max(ans, fact);
        }
        cout<<ans<<'\n';
    }
    
}