#include <bits/stdc++.h>
using namespace std;
 
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
 
 
int t;
 
cin >>t;
   
    u_int32_t k;
    u_int32_t ans;
    while (t--) {
        cin >> k;
        ans=pow((1+sqrt(1+4*k)),2);
        ans/=4;
        cout<<ans<<endl;
    }

    return 0;
}
 