#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin>> t;
  while(t--){
    int n;
    cin >> n;
    int arr[n];
    map<int,int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        mp[arr[i]] = i;
    }
  
    int count = 0;
    for (int i = 1; i <= 2*n; i++){
        for (int j = i+1; j<=2*n; j++) {
          if(i*j > 2*n)break;
          int prod = i*j;
          auto ind1 = mp.find(i);
          auto ind2 = mp.find(j);
          if(ind1 == mp.end() || ind2 == mp.end())continue;
          if((*ind1).second + (*ind2).second == prod)count++;
        }
    }
    cout << count<< endl;
  }
  return 0;
}