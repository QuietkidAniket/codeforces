#include <bits/stdc++.h>
#include <future>

using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void merge(vector<int>& data, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    
    while (i <= mid && j <= right) temp[k++] = (data[i] <= data[j]) ? data[i++] : data[j++];
    while (i <= mid) temp[k++] = data[i++];
    while (j <= right) temp[k++] = data[j++];
    
    copy(temp.begin(), temp.end(), data.begin() + left);
}

void parallelMergeSort(vector<int>& data, int left, int right, int depth) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        if (depth > 0) {
            // async : More portable and efficient for ARM architectures.
            // Thread-based parallelism: Uses std::async instead of OpenMP, avoiding overhead on unsupported systems.
            auto left_sort = async(launch::async, parallelMergeSort, ref(data), left, mid, depth - 1);
            parallelMergeSort(data, mid + 1, right, depth - 1);
            left_sort.wait();
        } else {
            sort(data.begin() + left, data.begin() + right + 1);
            return;
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
    cin >> n;
    
    int depth = thread::hardware_concurrency() > 1 ? log2(thread::hardware_concurrency()) : 1;
    
    while (n--) {
        parallelMergeSort(data, 0, data.size() - 1, depth);
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

