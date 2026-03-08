struct SparseTable{
    int n, l;
    vector<vector<int>> sp;
 
    inline int combine(int x, int y){
        return gcd(x, y);
        // fill this in
    }
 
    inline void init(int nn, vector <int> v){
        n = nn;
        if (v.size() == n){
            vector <int> v2;
            v2.push_back(0);
            for (auto x : v) v2.push_back(x);
            v = v2;
        }
 
        l = 0;
        while ((1 << l) <= n){
            l++;
        }
        sp = vector<vector<int>>(l, vector<int>(n + 1));
 
        for (int i = 1; i <= n; i++){
            sp[0][i] = v[i];
        }
 
        for (int j = 1; j < l; j++){
            for (int i = 1; i <= n; i++){
                int who = i + (1 << (j - 1));
                if (who <= n)
                sp[j][i] = combine(sp[j - 1][i], sp[j - 1][who]);
            }
        }
    }
 
    inline int query(int l, int r){
        int i = log2(r - l + 1);
        // cout << "QUERYING " << l << " " << r << " ";
        // cout << i << "\n";
        // cout << sp[i][l] << " " << sp[i][r + 1 - (1 << i)] << "\n";
        int v = combine(sp[i][l], sp[i][r + 1 - (1 << i)]);
        return v;
    }
};