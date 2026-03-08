/**
 * author: Anicetus_7
 * created: 2026-03-06 20:30:00
**/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int test_cnt = 1;

void Solve(){
    // Create separate file for each test case
    string filename = "input_" + to_string(test_cnt++) + ".in";
    ofstream fout(filename);

    // Bounds for large test cases to stress test constraints
    int n = 100000 - (RNG() % 1000);
    int max_extra = 21;
    int m = (n - 1) + (RNG() % (max_extra + 1));
    int q = 100000 - (RNG() % 1000);

    fout << n << " " << m << "\n";

    set<pair<int, int>> st;
    vector<int> vec(n);
    iota(vec.begin(), vec.end(), 1);
    shuffle(vec.begin(), vec.end(), RNG);

    // 1. Generate a valid tree to guarantee a connected graph
    for(int i = 1; i < n; i++){
        int u = vec[i];
        int v = vec[RNG() % i];
        int w = (RNG() % (int)1e9) + 1;

        fout << u << " " << v << " " << w << "\n";

        if(u > v) swap(u, v);
        st.insert({u, v});
    }

    // 2. Add extra edges while avoiding multi-edges and self-loops
    int cnt = m - (n - 1);
    while(cnt > 0){
        int u = (RNG() % n) + 1;
        int v = (RNG() % n) + 1;

        if(u == v) continue;
        if(u > v) swap(u, v);

        if(st.find({u, v}) == st.end()){
            st.insert({u, v});
            int w = (RNG() % (int)1e9) + 1;
            fout << u << " " << v << " " << w << "\n";
            cnt--;
        }
    }

    fout << q << "\n";

    // 3. Generate random queries
    for(int i = 0; i < q; i++){
        int u = (RNG() % n) + 1;
        int v = (RNG() % n) + 1;
        fout << u << " " << v << "\n";
    }

    fout.close();
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);

  int t = 5; // Hardcoded to generate 5 separate test files
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
