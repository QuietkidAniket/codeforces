/**
 *    author: Anicetus_7
 *    created: 2025-07-29 06:13:49
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

class DisjointSet{
public:
    vector<int> parents;
    vector<int> sizes;
    DisjointSet(int size) : parents(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) { parents[i] = i; }
    }
 
    /** @return the "representative" node in x's component */
    int find(int x) {
        return parents[x] == x ? x : (parents[x] = find(parents[x]));
    }
 
    /** @return whether the merge changed connectivity */
    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }
 
        if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }
 
    /** @return whether x and y are in the same connected component */
    bool connected(int x, int y) { return find(x) == find(y); }

    /** @return the number of components when all nodes in [start_index, end_index]  are considered */
    int n_components(int start_index, int end_index){
      int cnt =0;
      for(int i = start_index; i <= end_index; i++){
        cnt += (parents[i] == i);
      }
      return cnt;
    }
};


void Solve(){
  int n; cin>>n;
  vector<int> a(n+1);
  for(int i = 1; i<= n; i++)
  {
   cin>> a[i]; 
  }
  DisjointSet dsu(n+1);
  set<pair<int,int>> st;
  int cycles = 0;
  for(int i = 1; i <= n; i++){
    if(dsu.connected(a[i],i) && st.count({a[i],i}) == 0){
      cycles++;
    }else dsu.unite(i, a[i]);

    st.insert({i,a[i]});
  }
  int nc = dsu.n_components(1, n);
  if(nc - cycles > 0) cout << cycles + 1 << " " << nc << endl;
  else cout<< cycles  << " " << nc << endl;
  
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