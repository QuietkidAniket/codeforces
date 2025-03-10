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

cin>>t;
while(t--){
    int  n,  k;
    int ans {0};
    cin >> n >> k;
    int arr[n];
    int gold {0} ;

    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
        if(arr[i]  >= k)gold += arr[i];
        if(!arr[i]){
            if(gold >0 ){ 
                ans++;
                gold--;
            }
        }
    }
    
    // if(ans <= gold)cout << ans << '\n';
    // else {
    //     cout << gold << '\n';
    // }
    cout << ans << '\n';


}



return 0;
}