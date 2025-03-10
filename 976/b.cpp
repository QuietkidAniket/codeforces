#include <bits/stdc++.h>
using namespace std;




long long find_n(long long k) {
    long long n = k;  
    while (true) {
       
        long long sqrt_n = (long long)sqrt(n);
       
        if (n - sqrt_n == k) {
            return n;
        }
        n++;
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    int t;
    cin >> t; 
    
   
    while (t--) {
        long long k;
        cin >> k;
        cout << find_n(k) << endl;
    }
    
    return 0;
}