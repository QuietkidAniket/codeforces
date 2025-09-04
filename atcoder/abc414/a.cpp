#pragma optimize "O3"
#include <unistd.h>
/**
 *    author: Anicetus_7
 *    created: 2025-07-13
**/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)

bool isPalindrome(const string &s){
    int l = 0, r = s.size() - 1;
    while(l < r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int dx[] = {0,  0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0,  0, 1, -1,-1,  1};


//|------------------------------------------[MAIN]------------------------------------------|
int32_t solve(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; ++i){
        cin >> grid[i];
    }
    string word;
    cin >> word;
    int len = word.length();
    int count = 0;

    for(int x = 0; x < n; ++x){
        for(int y = 0; y < n; ++y){
            for(int dir = 0; dir < 8; ++dir){
                int nx = x, ny = y;
                int i;
                for(int i = 0; i < len; ++i){
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                    if(grid[nx][ny] != word[i]) break;
                    nx += dx[dir];
                    ny += dy[dir];
                }
                if(i == len) count++;
            }
        }
    }

    if(isPalindrome(word)) count /= 2;

    cout << count;    
;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int res = solve();
    printf("%lld", res);
}