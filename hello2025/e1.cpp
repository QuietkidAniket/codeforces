#include <bits/stdc++.h>
using namespace std;

void solve();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    int tt = clock();
    #endif
    solve();
    
    #ifndef ONLINE_JUDGE
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
    #endif
    return 0;
}
void solve(){
    int t;
    cin >>t;
    while(t--){
        // edges, vertices, queries
        int n, m, q;
        vector<pair<int,int>> adjl[n];
        for(int i = 0; i< m; i++)
        {   
            // u -w-> v 
            int u, v, w;
            cin >> u >>v>>w;
            adjl[u].push_back({v, w});
            adjl[v].push_back({u, w});
        }
        vector<vector<int>> queries(q);
        for(int i = 0; i < q; i++){
            int a,b,k;
            cin >> a>> b>>k;
            queries[i] = {a,b,k};
        }



        for(int i = 0 ; i < q; i++){
            // dijsktra for all queries
            int a = queries[i][0], b =queries[i][1], k = queries[i][2];
            vector<vector<int> > dis(n + 1, vector<int>(k, 1e9));
    
            // Initialization of priority queue
            priority_queue<pair<int, int>, vector<pair<int, int> >,greater<pair<int, int> > > pq;
            pq.push({ 0, 1 });
            dis[1][0] = 0;

            // while pq has elements
            while (!pq.empty()) {
                // Storing the node value
                int u = pq.top().second;
        
                // Storing the distance value
                int d = (pq.top().first);
                pq.pop();
                if (dis[u][k - 1] < d)
                    continue;
                vector<pair<int, int> > v = adjl[u];
        
                // Traversing the adjacency list
                for (int i = 0; i < v.size(); i++) {
                    int dest = v[i].first;
                    int cost = v[i].second;
        
                    // Checking for the cost
                    if (d + cost < dis[dest][k - 1]) {
                        dis[dest][k - 1] = d + cost;
        
                        // Sorting the distances
                        sort(dis[dest].begin(), dis[dest].end());
        
                        // Pushing elements to priority queue
                        pq.push({ (d + cost), dest });
                    }
                }
            }
            for (int i = 0; i < k; i++) {
            cout << dis[n][i] << " ";
            }
            cout << '\n';
        }
 
    }
    
}