#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

// always S = {1...n} is the given array, and Target T = {...} some target
// we need to perform S intersection T... 
// i.e, remove all the elements from S which are not in T.
// such as if S = {1,2,3...7} and T = {1,2,4,7}, then we need to remove 3,5,6.
// cost calculated =  k for the number being removed which is divisible by k 
//                    and the number is the smallest multiple of k in S

// Intuition:
// if 7 remains in S, hence no multiple greater than 7 can be removed from S using 7
// say if S = {1..14} and T is same, then 14 could not have been removed using 7
// so we can assume initial cost to remove 14 is 14,
// and then iterate down to 7 - on reaching which we break as 7 cannot be removed...
// and What if 7 could have been removed??
// then we would have updated 14's cost as 7 and 7's cost as 7 as well.
// hence this is a bottom up approach, approaching n -> 1 assuming the cost to be initially the number itself.



void Solve(){
		int n; cin>> n;
		set<int> rem;
		string s; cin>> s;
		vector<bool> mp(n+1, false);
		for(int i = 0; i< n;i++){
		 if(s[i] == '1')mp[i+1] = true;
		}
    int cost[n+1];
    memset(cost, 0, sizeof cost);

    // analogous to sieve of eratosthenes, following a bottom up approach
    for(int i = n; i >= 1; i--){
      for(int j = i; j <= n; j+=i){
        if(mp[j])break;
        cost[j] = i;
      }
    }
    ll ans = 0;
    for(int i = 1; i<= n; i++)
    { 
      if(!mp[i])ans += cost[i];
    }
		cout << ans;
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
  
  int t = 1;
  if(multi)cin>> t;
  while(t--){
  Solve();
  cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}