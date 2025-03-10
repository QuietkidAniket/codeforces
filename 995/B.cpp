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
    cin>> t;
    while(t--){
        int n, arr[3], sum = 0;
        cin >> n;
        for(int i = 0; i< 3; i++)
        {
            cin>> arr[i];
            sum += arr[i];
        }
        int day = (n / sum) * 3;
        n = n%sum;
        if(n == 0){
            cout << day << '\n';
            continue;
        }
        sum = 0;
        for(int i =0 ; i < 3; i++){
            sum += arr[i];
            if(n <= sum){
                cout << day + i + 1<< '\n';
                break;
            }
        }
    }
    
}