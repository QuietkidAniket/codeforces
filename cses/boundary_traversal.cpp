/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
struct Node{
    int val; unique_ptr<Node> left, right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};
void Solve(){
    vector<int> a;
    int x;
    while(cin>>x)a.push_back(x);
    // for(auto& x: a) cout << x << " ";
    int n = a.size();
    int idx = 0;
    unique_ptr<Node> head = make_unique<Node>(Node{a[0]});
    for(int i = 1;i < 29 && idx <n; i++){
        if(head->left){
            for(int j = idx; j < idx+(i<<i) && j< n; j++){
                int node = a[j];
                if(node!=-1)
            }
        }
        if(head->right){
            
        }
    }
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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
