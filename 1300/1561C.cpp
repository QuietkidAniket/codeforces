#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

bool bin_check(int power, vector<pair<vector<int>, int>>& caves){
  for(auto cave : caves){
    if(power <= cave.second)return false;
    power+= cave.first.size();
  }
  return true;
}



int bin_search_for_minpower(vector<pair<vector<int>,int>>& caves){
  int low = 0, high = 1e9+1;
  int ans = high;
  while(low <= high){
    int mid = (low + high)>>1;
    if(bin_check(mid, caves)){
      ans = mid;
      high = mid -1;
    }else{
      low = mid + 1;
    }
  }
  return ans;
}

bool comp(pair<vector<int>,int>& a, pair<vector<int>,int>& b){
  return (a.second < b.second);
}

void Solve(){
  int n; cin>> n;
  vector<pair<vector<int>, int>> caves(n);
  for(int i = 0; i< n; i++)
  {
    int k; cin>>k;
    int cave_max_elem = 0;
    vector<int> temp(k);
    for(int j =0; j < k; j++){
      cin>> temp[j];
      temp[j] -= j;
      cave_max_elem = max(cave_max_elem, temp[j]);
    }
    caves[i].first = temp;
    caves[i].second = cave_max_elem;
  }
  sort(caves.begin(), caves.end(), comp);
  // cout << "max_elem -> " << caves.back().second << endl;
  cout << bin_search_for_minpower(caves);
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