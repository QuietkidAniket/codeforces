#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
#define int long long

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;

typedef long long ll;
typedef long double ld;

static const int mod = 1e9;
const int inf = 1e9;
const int M = 1e9 + 7;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;

class DisjointSet{
vector<int> parent, size;
public:
DisjointSet(int n){
    parent.resize(n+1);
    size.resize(n+1, 1);
    // for 1 based indexing and 0 based indexing both
    for(int i = 0 ;i <= n ;i++){
        parent[i]= i;
    }
}

int findUPar(int node){
    if(node == parent[node])return node;
    return parent[node] = findUPar(parent[node]);
}

int n_components(int start, int end){
    int count = 0;
    for(int i = start; i <= end; i++){
        count += (int)(parent[i] == i);
    }
    return count;
}

void unionBySize(int u, int v){
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);

    if(ulp_u == ulp_v)return;
    if(size[ulp_u] > size[ulp_v]){
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }else{
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    }
}
};


void Solve(){
    int n,m1,m2;
    cin>> n >> m1 >> m2;
    vector<pair<int,int>> f(m1);
    vector<pair<int,int>> g(m2);

    DisjointSet dsG(n+1);
    for(int i = 0; i< m1; i++)
    {
        cin >> f[i].first >> f[i].second;
    }
    for(int i = 0; i< m2; i++)
    {
        cin >> g[i].first >> g[i].second;
        dsG.unionBySize(g[i].first, g[i].second);
    }

    int count = 0;
    DisjointSet dsF(n+1);
    for(int i = 0; i < m1; i++){
        int u = f[i].first, v = f[i].second;
        if(dsG.findUPar(u) != dsG.findUPar(v)){
            count++;
        }else dsF.unionBySize(u, v);
    }

    cout << count + dsF.n_components(1, n) - dsG.n_components(1,n);
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
    
    int t =1;
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