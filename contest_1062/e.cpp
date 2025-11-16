/**
 *    author: Anicetus_7
 *    created: 2025-10-28 20:56:38
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    int n,k,x;
    cin>>n>>k>>x;
    vector<int>a(n);
    for(auto &x:a)cin>>x;

    sort(a.begin(),a.end());  

    vector<int> res;
    auto check = [&](int target){
        res.clear();
        int L=-1, R =-1;
        vector<pair<int,int>> cover;
        for(int i =0 ;i < n ; i++){
            int l = max(0ll,a[i]- target);
            int r = min(x, a[i]+ target);
            if(l > R){ // new cover 
                if(R != -1)cover.push_back({L,R}); 
                L = l, R = r;
            }else{ // expand old cover
                R = r;
            }
        }
        cover.push_back({L,R});
        int i = 0;
        for(int pos = 0; pos <=x && res.size() < k; ){
            if(i < cover.size() && cover[i].first == pos){
                pos = cover[i].second+1;
                i++;
            }else res.push_back(pos++);
        }
    };
    
    int l =0, h = x;
    vector<int> ans;
    while(l <= h){
        int mid = (l+h)>>1;
        check(mid);
        if(res.size() == k){
            l = mid + 1;
            ans = res;
        }else h = mid -1;
    }
    if(ans.size() < k){
        for(int pos=0; pos<k;pos++){
            cout << pos << " ";
        }
    }else for(auto x:ans)cout<<x<<" ";
    cout<<endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin=chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);cin.tie(0);
  int t=1;
  cin>>t;
  for(int i=1;i<=t;i++)Solve();
  auto end=chrono::high_resolution_clock::now();
  auto elapsed=chrono::duration_cast<chrono::nanoseconds>(end-begin);
  cerr<<"Time measured: "<<elapsed.count()*1e-9<<" seconds.\n";
  return 0;
}