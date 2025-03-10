#include <bits/stdc++.h>
using namespace std;

void solve(){
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    
    int t;
    cin>>t;
   while(t--){
    set<int> X;
    
    int n;
    cin>> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    
    for(int i = 0 ; i < n-1; i ++){
        for(int j = i+1; j< n; j++)
        {   
            int sum = b[i] + b[j];
            // int min_b=  min(b[i], b[j]);
            int min_b = abs(b[i] -b[j]);

            for(int k = sum-1; k > min_b ; k--){
                X.insert(k);
            }

        }
    }


    cout << X.size() <<'\n';
    }
    
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
solve();


return 0;
}