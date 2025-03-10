#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O0")
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
static const int mod = 1000000007;

void Solve(){
    int m,n;
    cin>> m>>n;
    string s;
    cin>> s;
    vector<vector<ll>> grid(m, vector<ll>(n, 0));
    vector<ll> sum_rows(m, 0);
    vector<ll> sum_cols(n, 0); 
    for(int i = 0; i< m; i++)
    {
        for(int j = 0; j< n; j++)
        {
            cin>> grid[i][j];
            sum_rows[i] += grid[i][j];
            sum_cols[j] += grid[i][j];
        }   
    }
    int row = 0, col = 0;
    for(const auto& c: s){
        if(c == 'D'){  
            ll x = -sum_rows[row];
            grid[row][col] = x;
            sum_cols[col] += x;
            sum_rows[row] += x;
            row++;
        }else if(c == 'R'){
            ll x = -sum_cols[col];
            grid[row][col] = x;
            sum_cols[col] += x;
            sum_rows[row] += x;
            col++;
        }
    }
    // destination
    grid[m-1][n-1] = -sum_rows[m-1];

    for(int row = 0 ; row < m; row++){
        for(int col =0; col <n; col++){
            cout << grid[row][col] << " ";
        }
        cout << "\n";
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    auto begin = std::chrono::high_resolution_clock::now();
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    int tt = clock();
    #endif
    
    int t;
    cin>> t;
    while(t--){
    Solve();
    // cout << '\n';
    }
    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}
