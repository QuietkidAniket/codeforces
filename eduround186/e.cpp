/**
 *    author: Anicetus_7
 *    created: 2025-12-30 08:48:23
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n;cin>>n;
  int m;cin>>m;
  int k;cin>>k;

  vector<int> a(m);for(auto& x : a)cin>> x;
  vector<array<int,3>> vec(n);
  int toty =0;
  for(int i =0 ; i < n ; i++){
    cin>> vec[i][0]>>vec[i][1] >> vec[i][2];
    toty += vec[i][1];
  }
  int avail = k -  toty;
  
  sort(vec.rbegin(), vec.rend());
  sort(a.begin(), a.end());
  
  priority_queue<int, vector<int>, greater<>> pq;
  vector<int> rem;
  int ptra = m-1;
  for(int i =0; i <n; i++){
    while(ptra >=0&& a[ptra] >= vec[i][0])ptra--;
    int diff = vec[i][2]- vec[i][1];
    int dist = m-ptra;
    if(dist > pq.size()+1){
      pq.push(diff);
    }else{
      // if i have more than 'dist' elements in the list of candidates
      // then we need to have the one with smallest diff
      if(!pq.empty() && pq.top() < diff){
        pq.push(diff);
        rem.push_back(pq.top());
        pq.pop();
      }else{
        rem.push_back(diff);
      }
    }
  }
  sort(rem.begin(), rem.end());
  int ans = pq.size();
  for(int i =0;i < rem.size(); i++){
    if(avail - rem[i] >= 0){avail -= rem[i]; ans++;}
    else break;
  }
  cout << ans << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}