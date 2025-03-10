#include <bits/stdc++.h>
using namespace std;
// typedef long double ld;
#define int long long
// typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const long long mod = 1e9 + 7;


int power(int x, int y) {
    int res = 1;
    x = x % mod; 
    while (y > 0) {  
        if (y & 1) 
            res = (res * x) % mod;  
        y = y >> 1;
        x = (x * x) % mod;   
    } 
    return res; 
}


void Solve(){
  int n, k;
  cin>> n>>k;
  vector<int> arr(n);
  int n_zeros = 0;
  for(int i = 0; i< n; i++)
  {
   cin>> arr[i];
   if(arr[i] == 0)n_zeros++;
  }
  if(n_zeros == 0){cout << 1; return;}

  int total_possible_permutations = power(k, n_zeros);

  // if 0,0,a,0,0,c,0, then we transform into 0,c,a,0,a,c,0 so that we can calculate the total number of permutations
  for(int i= 0; i <n/2; i++){
      if(arr[i] == 0 && arr[n-1-i] != 0)arr[i]=arr[n-1-i];
      else if(arr[i] != 0 && arr[n-1-i] == 0)arr[n-1-i]=arr[i];
      // if 0,0,a,0,b,0,0 -> then no palindromes are possible
      else if(arr[i] != 0 && arr[n-1-i] != 0 && arr[n-1-i]!=arr[i]){
        cout << total_possible_permutations;
        return;
      } 
  }

  int n_zeros_for_palindrome = 0;
  for(int i = 0; i < n; i++){
    if(arr[i] == 0)n_zeros_for_palindrome++;
  }

  int possible_permutations_2 = power(k, n_zeros_for_palindrome);

  int exp = n_zeros_for_palindrome/2;
  // check if middle element is 0
  if(n%2 == 1 && arr[n/2] == 0)exp++;
  int n_palindromes = power(k, exp);

  // ans = no. of palindromes + no. of non-palindromes without their reverses
  // each non-palindromes have their reverse
  // hence divide by two to get no. of non-palindromes without their reverses
  // Therefore, ans =no. of permutations + (no. of non_palindromes)/2
  // where no. of non-palindromes = n_combinations - n_palindromes
  int ch = (possible_permutations_2 - n_palindromes +mod);
    ch %=mod;
    ch *= power(2, mod-2);
    ch %=mod;

  cout << ( n_palindromes + ch +mod)%mod;
}
signed main()
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