#include <bits/stdc++.h>
#include "omp.h"

using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void merge(vector<int>& data, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = data[left + i];
    for (int i = 0; i < n2; i++) R[i] = data[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) data[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) data[k++] = L[i++];
    while (j < n2) data[k++] = R[j++];
}

void parallelMergeSort(vector<int>& data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            parallelMergeSort(data, left, mid);

            #pragma omp section
            parallelMergeSort(data, mid + 1, right);
        }

        merge(data, left, mid, right);
    }
}

void loadData(vector<int>& data, const string &filename) {
    ifstream file(filename);
    int x;
    while (file >> x) data.push_back(x);
    file.close();
}

void Solve() {
    vector<int> data;
    
    loadData(data, "input.txt");
    
    
    int n;
    cin>> n;
    
    while(n--){
        parallelMergeSort(data, 0, data.size() - 1);
        cout << "Sorted! \n";
    }
    
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    int tt = clock();
    auto begin = std::chrono::high_resolution_clock::now();
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    #endif
    
    int t = 1;
    if(multi)cin>> t;
    while(t--){
        Solve();
        cout << endl;
    }
    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}


// int main() {
//     FILE *file = fopen("input.txt", "r");
//     int n;
//     fscanf(file, "%d", &n);
//     int *data = (int *)malloc(n * sizeof(int));
//     for (int i = 0; i < n; i++) fscanf(file, "%d", &data[i]);
//     fclose(file);

    
//     return 0;
// }