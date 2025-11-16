/**
 * Disjoint Set Union (0 indexed) 
 * Use only find() to judge number of components.
 */
class DisjointSet{
public:
    vector<int> parents;
    vector<int> sizes;
    DisjointSet(int size) : parents(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) { parents[i] = i; }
    }
 
    /** @return the "representative" node in x's component */
    int find(int x) {
        return parents[x] == x ? x : (parents[x] = find(parents[x]));
    }
 
    /** @return whether the merge changed connectivity */
    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }
 
        if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }
 
    /** @return whether x and y are in the same connected component */
    bool connected(int x, int y) { return find(x) == find(y); }
};


 
/**
 * Modulo Integer modulo mod
 */
const int mod = 998244353;
struct mint{
    int x;
 
    mint (){ x = 0;}
    mint (int32_t xx){ x = xx % mod; if (x < 0) x += mod;}
    mint (long long xx){ x = xx % mod; if (x < 0) x += mod;}
 
    int val(){
        return x;
    }
    mint &operator++(){
        x++;
        if (x == mod) x = 0;
        return *this;
    }
    mint &operator--(){
        if (x == 0) x = mod;
        x--;
        return *this;
    }
    mint operator++(int32_t){
        mint result = *this;
        ++*this;
        return result;
    }
    
    mint operator--(int32_t){
        mint result = *this;
        --*this;
        return result;
    }
    mint& operator+=(const mint &b){
        x += b.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint &b){
        x -= b.x;
        if (x < 0) x += mod;
        return *this;
    }
    mint& operator*=(const mint &b){
        long long z = x;
        z *= b.x;
        z %= mod;
        x = (int)z;
        return *this;
    }
    mint operator+() const {
        return *this;
    }
    mint operator-() const {
        return mint() - *this;
    }
    mint operator/=(const mint &b){
        return *this = *this * b.inv();
    }
    mint power(long long n) const {
        mint ok = *this, r = 1;
        while (n){
            if (n & 1){
                r *= ok;
            }
            ok *= ok;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        return power(mod - 2);
    }
    friend mint operator+(const mint& a, const mint& b){ return mint(a) += b;}
    friend mint operator-(const mint& a, const mint& b){ return mint(a) -= b;}
    friend mint operator*(const mint& a, const mint& b){ return mint(a) *= b;}
    friend mint operator/(const mint& a, const mint& b){ return mint(a) /= b;}
    friend bool operator==(const mint& a, const mint& b){ return a.x == b.x;}
    friend bool operator!=(const mint& a, const mint& b){ return a.x != b.x;}
    mint power(mint a, long long n){
        return a.power(n);
    }
    friend ostream &operator<<(ostream &os, const mint &m) {
        os << m.x;
        return os;
    }
    explicit operator bool() const {
        return x != 0;
    }
};
// Remember to check MOD


/**
 * Combinations, factorial and inverse factorial modulo MOD
 */
*/
const int MAXN = 2e5 + 5;
static int fact[MAXN+1], invfact[MAXN+1];
int modPow(int base, int exp) {
  int res = 1;
  while (exp > 0) {
      if (exp & 1ll) res = (res * base) % MOD;
      base = (base * base) % MOD;
      exp >>= 1ll;
  }
  return res;
}

int modinv(int a) {
    return modPow(a, MOD - 2);
}
static bool flag = false;
void precompute_combinations(){
    fact[0] = invfact[0] = 1;
    for(int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
      }
    
    invfact[MAXN] = modinv(fact[MAXN]);
    for(int i = MAXN-1; i >= 0;i--){
      invfact[i] = invfact[i+1]*(i+1) % MOD;
    }
}
int C(int n, int r) {
    if(!flag){precompute_combinations();flag = true;}
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}
// _________________ dont forget to run precompute_combinations() !______________


// Sum Segment Tree with Lazy Propagation
// Supports Range Add & Range Sum Queries
const int M = 200005; // Maximum array size
int seg[4 * M];
int lazy[4 * M];
vector<int> a;

void build(int l, int r, int pos) {
  if (l == r) {
    seg[pos] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, pos * 2);
  build(mid + 1, r, pos * 2 + 1);
  seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
}

void push(int l, int r, int pos) {
  if (lazy[pos] == 0) return;
  // Add lazy value times the number of elements in the range
  seg[pos] += lazy[pos] * (r - l + 1);
  if (l != r) {
    lazy[pos * 2] += lazy[pos];
    lazy[pos * 2 + 1] += lazy[pos];
  }
  lazy[pos] = 0;
}

// Add 'qval' to all elements in range [ql, qr]
void update(int l, int r, int pos, int ql, int qr, int qval) {
  push(l, r, pos);
  if (ql > r || qr < l) return;
  if (ql <= l && qr >= r) {
    lazy[pos] += qval;
    push(l, r, pos);
    return;
  }
  int mid = (l + r) / 2;
  update(l, mid, pos * 2, ql, qr, qval);
  update(mid + 1, r, pos * 2 + 1, ql, qr, qval);
  
  // Recalculate sum after updating children
  push(l, mid, pos * 2);
  push(mid + 1, r, pos * 2 + 1);
  seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
}

// Query the sum of elements in range [ql, qr]
int query(int l, int r, int pos, int ql, int qr) {
  push(l, r, pos);
  if (ql > r || qr < l) return 0; // 0 is the identity for sum
  if (ql <= l && qr >= r) return seg[pos];
  
  int mid = (l + r) / 2;
  int left_res = query(l, mid, pos * 2, ql, qr);
  int right_res = query(mid + 1, r, pos * 2 + 1, ql, qr);
  return left_res + right_res;
}

// Min Segment Tree with Lazy Propagation
// Supports Range Add & Range Min Queries
const int M = 200005; // Maximum array size
const int INF = 1e18; // Identity for min
int seg[4 * M];
int lazy[4 * M];
vector<int> a;

void build(int l, int r, int pos) {
  if (l == r) {
    seg[pos] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, pos * 2);
  build(mid + 1, r, pos * 2 + 1);
  seg[pos] = min(seg[pos * 2], seg[pos * 2 + 1]);
}

void push(int l, int r, int pos) {
  if (lazy[pos] == 0) return;
  // Add lazy value to the current node's value
  seg[pos] += lazy[pos];
  if (l != r) {
    lazy[pos * 2] += lazy[pos];
    lazy[pos * 2 + 1] += lazy[pos];
  }
  lazy[pos] = 0;
}

// Add 'qval' to all elements in range [ql, qr]
void update(int l, int r, int pos, int ql, int qr, int qval) {
  push(l, r, pos);
  if (ql > r || qr < l) return;
  if (ql <= l && qr >= r) {
    lazy[pos] += qval;
    push(l, r, pos);
    return;
  }
  int mid = (l + r) / 2;
  update(l, mid, pos * 2, ql, qr, qval);
  update(mid + 1, r, pos * 2 + 1, ql, qr, qval);
  
  // Recalculate min after updating children
  push(l, mid, pos * 2);
  push(mid + 1, r, pos * 2 + 1);
  seg[pos] = min(seg[pos * 2], seg[pos * 2 + 1]);
}

// Query the min of elements in range [ql, qr]
int query(int l, int r, int pos, int ql, int qr) {
  push(l, r, pos);
  if (ql > r || qr < l) return INF;
  if (ql <= l && qr >= r) return seg[pos];
  
  int mid = (l + r) / 2;
  int left_res = query(l, mid, pos * 2, ql, qr);
  int right_res = query(mid + 1, r, pos * 2 + 1, ql, qr);
  return min(left_res, right_res);
}

// GCD Segment Tree
// Supports Point Update & Range GCD Queries
const int M = 200005; // Maximum array size
int seg[4 * M];
vector<int> a;

void build(int l, int r, int pos) {
  if (l == r) {
    seg[pos] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, pos * 2);
  build(mid + 1, r, pos * 2 + 1);
  seg[pos] = __gcd(seg[pos * 2], seg[pos * 2 + 1]);
}

// Set value at index 'q_idx' to 'qval'
void update(int l, int r, int pos, int q_idx, int qval) {
  if (l == r) {
    seg[pos] = qval;
    return;
  }
  int mid = (l + r) / 2;
  if (q_idx <= mid) {
    update(l, mid, pos * 2, q_idx, qval);
  } else {
    update(mid + 1, r, pos * 2 + 1, q_idx, qval);
  }
  seg[pos] = __gcd(seg[pos * 2], seg[pos * 2 + 1]);
}

// Query the GCD of elements in range [ql, qr]
int query(int l, int r, int pos, int ql, int qr) {
  if (ql > r || qr < l) return 0; // 0 is the identity for GCD (gcd(x,0)=x)
  if (ql <= l && qr >= r) return seg[pos];
  
  int mid = (l + r) / 2;
  int left_res = query(l, mid, pos * 2, ql, qr);
  int right_res = query(mid + 1, r, pos * 2 + 1, ql, qr);
  
  if (left_res == 0) return right_res;
  if (right_res == 0) return left_res;
  return __gcd(left_res, right_res);
}


// Distinct Elements (Bitmask) Segment Tree with Lazy Propagation
// Supports Range Add & Range Distinct Element Count Queries
// NOTE: Only works for small element values (0 <= value < 64)
const int M = 200005; // Maximum array size
int seg[4 * M];
int lazy[4 * M];
vector<int> a;

void build(int l, int r, int pos) {
  if (l == r) {
    seg[pos] = (1LL << a[l]);
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, pos * 2);
  build(mid + 1, r, pos * 2 + 1);
  seg[pos] = seg[pos * 2] | seg[pos * 2 + 1];
}

void push(int l, int r, int pos) {
  if (lazy[pos] == 0) return;
  // Shifting the bitmask is equivalent to adding lazy[pos] to all elements
  seg[pos] <<= lazy[pos]; 
  if (l != r) {
    lazy[pos * 2] += lazy[pos];
    lazy[pos * 2 + 1] += lazy[pos];
  }
  lazy[pos] = 0;
}

// Add 'qval' to all elements in range [ql, qr]
void update(int l, int r, int pos, int ql, int qr, int qval) {
  push(l, r, pos);
  if (ql > r || qr < l) return;
  if (ql <= l && qr >= r) {
    lazy[pos] += qval;
    push(l, r, pos);
    return;
  }
  int mid = (l + r) / 2;
  update(l, mid, pos * 2, ql, qr, qval);
  update(mid + 1, r, pos * 2 + 1, ql, qr, qval);
  
  // Recalculate bitmask after updating children
  push(l, mid, pos * 2);
  push(mid + 1, r, pos * 2 + 1);
  seg[pos] = seg[pos * 2] | seg[pos * 2 + 1];
}

// Query the combined bitmask for elements in range [ql, qr]
// To get the count, use __builtin_popcountll on the result.
int query(int l, int r, int pos, int ql, int qr) {
  push(l, r, pos);
  if (ql > r || qr < l) return 0; // 0 is the identity for bitwise OR
  if (ql <= l && qr >= r) return seg[pos];
  
  int mid = (l + r) / 2;
  int left_res = query(l, mid, pos * 2, ql, qr);
  int right_res = query(mid + 1, r, pos * 2 + 1, ql, qr);
  return left_res | right_res;
}

/**
 * Sqrt decomposition for minimum element
 */
class Sqrt_decomposition{
 private:
int n;
vector<int> a; // actual array
vector<int> block; // block representation of the array, stores minimum in each block
int block_size; // size of block
int s; // no . of blocks
public:
void init(const vector<int>& arr){
  this->n = arr.size();
  this->a= arr;
  this->block_size = max(1ll,(int)sqrt((int)a.size()));
  this->s = (n+block_size-1)/block_size;
  build();
}
void build(){
  block.resize(s, 1e9);
  for(int i = 0; i < n; i++){
    int idx= i/block_size;
    block[idx] = min(block[idx], a[i]);
  }
}

int query(int l, int r){
  int ans = 1e9;
  int left_block = l / block_size;
  int right_block = r / block_size;

  // l,r within a single block
  if (left_block == right_block) {
      for (int i = l; i <= r; ++i) ans = min(ans, a[i]);
      return ans;
  }

  // left partial block
  int left_end = min(n - 1, (left_block + 1) * block_size - 1);
  for (int i = l; i <= left_end; ++i) ans = min(ans, a[i]);

  // full blocks
  for (int b = left_block + 1; b <= right_block - 1; ++b) {
      ans = min(ans, block[b]);
  }

  // right partial block
  int right_start = right_block * block_size;
  for (int i = right_start; i <= r; ++i) ans = min(ans, a[i]);

  return ans;
}
void update(int i, int new_val){
  a[i]  = new_val;
  int blk_id = i/block_size;
  block[blk_id] = 1e9;
  for(int idx = blk_id*block_size; idx < min(n, (blk_id+1)*block_size) ; idx++){
    block[blk_id] = min(a[idx], block[blk_id]);
  }
}
};


/**
 * Lowest Common Ancestor in Tree
 * Using Binary Lifting
 */
struct Tree {
    vector<vector<int>> adj, lift;
    vector<int> d, tin, tout, par;
    int n, timer;
    bool initialized = false;
    bool dfsed = false;

    /**
     * @brief Initialize tree data structures
     * @param nn number of nodes
     */
    void init(int nn){
        n = nn;
        adj.resize(n + 1);
        d.resize(n + 1);
        lift.resize(n + 1);
        tin.resize(n + 1);
        tout.resize(n + 1);
        par.resize(n + 1);
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 0; i <= n; i++) lift[i].resize(20, 0);
        initialized = true;
    }

    /**
     * @brief Add undirected edge between u and v
     */
    void addEdge(int u, int v){
        if (!initialized){
            cout << "STUPID INITIALIZE\n";
            exit(0);
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /**
     * @brief Build binary lifting table (2^j ancestors)
     */
    void build(){
        for (int j = 1; j < 20; j++){
            for (int i = 1; i <= n; i++){
                lift[i][j] = lift[lift[i][j - 1]][j - 1];
            }
        }
    }

    /**
     * @brief DFS traversal to compute depths, parents, entry/exit times
     * @param u current node
     * @param par1 parent of current node
     */
    void dfs(int u, int par1){
        par[u] = par1;
        tin[u] = ++timer;
        for (int v : adj[u]){
            if (v != par1){
                d[v] = d[u] + 1;
                lift[v][0] = u;
                dfs(v, u);
            }
        }
        tout[u] = timer;
    }

    /**
     * @brief Wrapper DFS from root, also builds binary lifting table
     * @param root root of the tree (default = 1)
     */
    void dfs(int root = 1){
        if (!initialized){
            cout << "STUPID INITIALIZE\n";
            exit(0);
        }
        d[root] = 0;
        timer = 0;
        dfs(root, 0);
        build();
        dfsed = true;
    }

    /**
     * @brief Jump up by given depth using binary lifting
     * @return ancestor of node x after climbing 'depth' levels
     */
    int jump(int x, int depth){
        for (int i = 0; i < 20; i++) if (depth >> i & 1){
            x = lift[x][i];
        }
        return x;
    }

    /**
     * @brief Compute Lowest Common Ancestor (LCA) of two nodes
     * @return LCA of nodes a and b
     */
    int lca(int a, int b){
        if (!dfsed){
            cout << "STUPID DFS\n";
            exit(0);
        }
        if (d[a] < d[b]) swap(a, b);
        int del = d[a] - d[b];
        for (int i = 0; i < 20; i++) if (del >> i & 1) a = lift[a][i];

        if (a == b) return a;

        for (int i = 19; i >= 0; i--) if (lift[a][i] != lift[b][i]){
            a = lift[a][i];
            b = lift[b][i];
        }
        return lift[a][0];
    }

    /**
     * @brief Compute distance between two nodes
     * @return number of edges in path between a and b
     */
    int dist(int a, int b){
        return d[a] + d[b] - 2 * d[lca(a, b)];
    }

    /**
     * @brief Check if x is ancestor of y
     * @return true if x is ancestor of y
     */
    bool anc(int x, int y){
        return tin[x] <= tin[y] && tout[x] >= tout[y];
    }
};



/**
 * Matrix Exponentation for fibonacci Numbers
 */
struct matrix{
  int n, m;
  vector<vector<int>> mat;
  
  matrix(): n(0), m(0) {}
  matrix(int n_, int m_, const vector<vector<int>>& mat_): n(n_), m(m_), mat(mat_){}
  
  /**
   * evaluates C(n,m) = A(n,p) x B(p,m)
   * C[i][j]= ∑ A[i][k] * B[k][j]
  */
  matrix operator*(const matrix& B){
    const auto A = *this;
    matrix C = {A.n, B.m, vector<vector<int>>(A.n, vector<int>(B.m, 0))};
    for(int i =0 ; i < A.n; i++){
      for(int j = 0; j < B.m; j++){
        for(int k = 0; k < A.m; k++){
          C.mat[i][j] += A.mat[i][k]*B.mat[k][j];
        }
        C.mat[i][j] %= MOD;
      }
    }  
    return C;
  }
  
};

matrix matrixpow(matrix base, int exp){
  matrix res = {2,2 ,{{1,0}, {0,1}}};
  while(exp > 0){
    if(exp&1){
      res = res * base;
    }
    base = base* base;
    exp >>=1;
  }
  return res;
}
