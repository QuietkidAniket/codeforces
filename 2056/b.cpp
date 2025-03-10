#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
#define ll long long
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
static const int mod = 1000000007;

void Solve(){
    int n;
    cin>>n;
    vector<vector<int>> g(n+1, vector<int>(n+1, 0));
    for(int i = 1; i<= n; i++){
        string s;
        cin>> s;
        for(int j = 1; j <= n; j++){
            g[i][j] = s[j-1] == '1';
        }
    }

    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);

    for(int i =1; i<= n; i++){
        for(int j = i+1; j<= n; j++)
        {   
            // i - j
            if(g[i][j]){
                indegree[j]++;
                adj[i].push_back(j);
            }else{
                indegree[i]++;
                adj[j].push_back(i);
            }
        }
    }
    // topo sort : u -> v =>  v,u
    queue<int> q;
    for(int i =1; i<= n; i++)
    {
        if(!indegree[i])q.push(i);
    }

    while(!q.empty()){
        int node= q.front(); q.pop();
        cout << node << " ";
        for(const auto& adjnode: adj[node]){
            indegree[adjnode]--;
            if(!indegree[adjnode]){
                    q.push(adjnode);
                }
        }
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
    
    int t;
    cin>> t;
    while(t--){
    Solve();
    cout << '\n';
    }
    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}