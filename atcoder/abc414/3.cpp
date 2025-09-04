/**
 *    author: Anicetus_7
 *    created: 2025-07-13 16:30:00
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = (int)1e18;

struct Edge {
    int to, rev, cap;
    int cost;
};

// ***dekhke copy karna, NO galti honi chahiye***
struct MinCostMaxFlow {
    int n;
    vector<vector<Edge>> g;
    MinCostMaxFlow(int _n) : n(_n), g(_n) {}

    void addEdge(int u, int v, int cap, int cost) {
        Edge a{v, (int)g[v].size(), cap, cost};
        Edge b{u, (int)g[u].size(), 0, -cost};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    // returns {flow, cost}
    pair<int,int> maxFlowMinCost(int s, int t, int need) {
        int flow = 0, cost = 0;
        vector<int> dist(n), pv(n), pe(n), pot(n, 0);

        while (flow < need) {
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0, s});
            while (!pq.empty()) {
                auto [d, v] = pq.top(); pq.pop();
                if (d != dist[v]) continue;
                for (int i = 0; i < (int)g[v].size(); ++i) {
                    auto &e = g[v][i];
                    if (e.cap && dist[e.to] > d + e.cost + pot[v] - pot[e.to]) {
                        dist[e.to] = d + e.cost + pot[v] - pot[e.to];
                        pv[e.to] = v;
                        pe[e.to] = i;
                        pq.push({dist[e.to], e.to});
                    }
                }
            }
            if (dist[t] == INF) break;          // should not happen – guaranteed feasible
            for (int v = 0; v < n; ++v) pot[v] += dist[v];
            int add = 1;                        // all capacities are 1 so path flow is 1
            for (int v = t; v != s; v = pv[v])
                add = min(add, g[pv[v]][pe[v]].cap);

            flow += add;
            for (int v = t; v != s; v = pv[v]) {
                auto &e = g[pv[v]][pe[v]];
                e.cap -= add;
                g[v][e.rev].cap += add;
                cost += add * e.cost;
            }
        }
        return {flow, cost};
    }
};

int main() {
    int N, K;
    if (!(cin >> N >> K)) return;
    vector<vector<int>> a(N, vector<int>(N));
    int totalSum = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
            totalSum += a[i][j];
        }

    auto id = [N](int r, int c) { return r * N + c; };
    int V = N * N + 2;
    int S = V - 2, T = V - 1;
    MinCostMaxFlow mcmf(V);

    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            int u = id(r, c);
            if ((r + c) & 1) continue;               // “black” cells only
            mcmf.addEdge(S, u, 1, 0);                // capacity 1, cost 0
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                int v = id(nr, nc);
                int w = -(a[r][c] + a[nr][nc]);      // negative for max-weight
                mcmf.addEdge(u, v, 1, w);
            }
        }
    }
    // white cells → sink
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            if ((r + c) & 1)
                mcmf.addEdge(id(r, c), T, 1, 0);

    auto [flow, negCost] = mcmf.maxFlowMinCost(S, T, K);
    // flow == K by problem guarantee

    int covered = -negCost;          // we stored costs as negative
    cout << totalSum - covered << '\n';
    return 0;
}


//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}