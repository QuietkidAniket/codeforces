/**
 *    author: Anicetus_7
 *    created: 2025-08-10 18:50:09
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int e(string s, unordered_map<char,int>& mp){
  int num  =0;
  for(const char c: s){
    num = num*10 + mp[c];
  }
  return num;
}

int solution(vector<string> crypt){
  string a= crypt[0], b= crypt[1], c = crypt[2];
  set<char> st(a.begin(), a.end());
  st.insert(b.begin(), b.end());
  st.insert(c.begin(), c.end());


  int cnt = 0;
  
  vector<char> letters;
  letters.assign(st.begin(), st.end());

  int n= letters.size();
  
  vector<int> digits(10);
  iota(digits.begin(), digits.end(), 0);

  vector<int> chosen(10);
  iota(chosen.begin(), chosen.end(), 0);

  sort(digits.begin(), digits.end());
  do {
      unordered_map<char, int> mapping;
      for (int i = 0; i < n; i++) {
          mapping[letters[i]] = digits[i];
      }
      
      int A = e(a, mapping);
      int B = e(b, mapping);
      int C = e(c, mapping);
      if(A+B == C){
        cnt++;
      }
  } while (next_permutation(digits.begin(), digits.end()));
  cout << cnt << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}