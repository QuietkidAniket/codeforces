#include <bits/stdc++.h>
using namespace std;

void solve(){
    int m, n;
    cin >> m >>n;

    int pfx[m+1][n+1];
    pfx[0][0] =0;
    for(int i = 1 ; i <= m; i++){
        pfx[i][0] = 0;
        for(int j  = 1; j <= n; j++){
            pfx[0][j] = 0;
            int x; 
            cin >> x;
            pfx[i][j]= x + pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1];
        }
    }

    // for(int i = 0; i<= m; i++)
    // {
    //     for(int j = 0; j<= n; j++)
    //     {
            
    //     cout << pfx[i][j] << ", "; 
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // query : 
    int from_row, from_col, to_row, to_col;
    cin>> from_row >> from_col >> to_row>> to_col;
    cout << pfx[to_row][to_col] - pfx[from_row-1][to_col] - pfx[to_row][from_col-1] + pfx[from_row-1][from_col-1];
    
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