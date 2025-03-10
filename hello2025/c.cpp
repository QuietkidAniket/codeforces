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
    
    #ifndef ONLINE_JUDGE
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
    #endif
    return 0;
}
void solve(){
    int t;
    cin >> t;

    while(t--){
        int l, r;
        cin >>l >>r;
        int ans = 0;
        vector<int> vec_ans= {-1,-1,-1};
        for(int i = l; i<=r-2; i++){
            for(int j = i+1; j<=r-1; j++){
                for(int k = j +1; k <= r;k++){
                    int res = i ^ j ^k;
                    if(ans< res){
                        ans = res;
                        vec_ans = {i,j,k};
                    }
                }
            }
        }
        for(const auto& x : vec_ans)
        {
            cout << x <<" ";
        }
        cout << "\n";
    }
}