#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n, p;
  cin>> n>> p;

  vector<int> arr(n);
  for(int i = 0; i< n; i++)cin >> arr[i];


  int c_left= 0;
  int max_left = 0;
  vector<int> left(n,0); // by default 0
  vector<int> left_count(n,0);
  // get the number of volcanoes from left
  // and also get the max_building from left after a volcano
  for(int i = 0; i< n; i++)
  {
    if(arr[i]== 0){ // if volcano
      left[i] = max_left= 0;
      c_left++;
    }else{
      left[i] = max_left= max(max_left, arr[i]);
      left_count[i] = c_left;
    }
  }

  int c_right= 0;
  int max_right = 0;
  vector<int> right(n,0); // by default 0
  vector<int> right_count(n,0);
  // get the number of volcanoes from right
  // and also get the max_building from right after a volcano
  for(int i = n-1; i>=0; i--)
  {
    if(arr[i]== 0){ // if volcano
      right[i] = max_right= 0;
      c_right++;
    }else{
      right[i] = max_right= max(max_right, arr[i]);
      right_count[i] = c_right;
    }
  }


  vector<int> ans(n,0);
  for(int i= 0; i < n; i++){
    // volcano on both sides
    if(right_count[i] > 0 && left_count[i] > 0)ans[i] = min(right[i],left[i]);
    else if(right_count[i] > 0 && left_count[i] == 0)ans[i] = right[i];
    else ans[i] = left[i];
  }
  for(int i = 0; i< n; i++)
  {
    cout <<  (ans[i] / p) + (ans[i]%p > 0? 1 : 0) << " ";
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