#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    
    // your code goes here
    int t;
    cin >> t;
    
    while(t--){
        int n ,k;
        cin>> n >>k;
        // cout << n <<  k;
        int sum = 0;
        int x;
        int arr[n];
        for(int i = 0 ; i< n ; i++){
            cin >>arr[i];
        }
        int i = 1;
        for(; i <= n; i++){
            if(sum +arr[i-1] > k){ 
                break;
            }else sum += arr[i-1];
        }
        cout<< i -1 <<'\n';
    }
    
    
}


int main()
{
// ios::sync_with_stdio(0);
// cin.tie(0);
// cout.tie(0);

freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);

solve();

return 0;
}


