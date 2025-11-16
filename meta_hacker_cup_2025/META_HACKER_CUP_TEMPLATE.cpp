/**
 *    author: Anicetus_7
 *    created: 2025-10-18 21:33:04
**/
#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    
}


//|------------------------------------------[MAIN]------------------------------------------|
int32_t main_(){
    auto begin = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t = 1;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": \n";
        Solve();
    }
    
    auto end = chrono::high_resolution_clock::now(); 
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin); 
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}
void* run_main(void*) {
    main_(); 
    return nullptr;
}

int32_t main() {
    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    size_t stack_size = 1024UL * 1024UL * 1024UL; // 1 GB
    pthread_attr_setstacksize(&attr, stack_size);

    if (pthread_create(&thread, &attr, run_main, nullptr) != 0) {
        perror("pthread_create");
        return 1;
    }

    pthread_join(thread, nullptr);
    pthread_attr_destroy(&attr);

    return 0;
}