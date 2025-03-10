#include <bits/stdc++.h>
using namespace std;






int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
// freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
// freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);

int t;
cin>> t;

while(t--){
    int n, k;
    cin>> n >> k;
    int count{0};
    if(k == 1){
        cout << n <<'\n';
        continue;
    }else if( n == 1){
        cout << 1 << '\n';
        continue;
    }
    while(n != 0){
        count += n %k;
        n/= k;
    }

    cout << count << '\n';
    
}


return 0;
}