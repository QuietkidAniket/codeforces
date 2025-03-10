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

cin>> t;
while(t--){
    int n , k;
    cin>> n>>k;
    int offset  = k -1;

    long int sum =  (n * (n+1 ) - (n - k )*(n - k + 1))/2;

    if((sum & 1) == 0)cout << "YES" << '\n';
    else cout << "NO" << '\n';
}


return 0;
}