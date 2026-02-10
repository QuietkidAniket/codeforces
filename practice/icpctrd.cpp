/* Segment tree for sum queries*/
struct SegTree {
    int n;
    vector<int> seg;
    vector<int> lazy;

    SegTree(int _n) {
        n = _n;
        seg.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
    }

    void push(int l, int r, int pos) {
        if (lazy[pos] == 0) return;
        seg[pos] += lazy[pos] * (r - l + 1);
        if (l != r) {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    void build(const vector<int>& a, int l, int r, int pos) {
        if (l == r) {
            seg[pos] = a[l - 1];
            return;
        }
        int mid = (l + r) / 2;
        build(a, l, mid, pos * 2);
        build(a, mid + 1, r, pos * 2 + 1);
        seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
    }

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
        seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
    }

    int query(int l, int r, int pos, int ql, int qr) {
        push(l, r, pos);
        if (ql > r || qr < l) return 0;
        if (ql <= l && qr >= r) return seg[pos];
        int mid = (l + r) / 2;
        return query(l, mid, pos * 2, ql, qr) + query(mid + 1, r, pos * 2 + 1, ql, qr);
    }

    void build(const vector<int>& a) { build(a, 1, n, 1); }
    void update(int ql, int qr, int val) { update(1, n, 1, ql, qr, val); }
    int query(int ql, int qr) { return query(1, n, 1, ql, qr); }
};

/* Segment tree for min queries */
struct SegTree {
    int n;
    vector<int> seg, lazy;
    // [SWITCH] For MAX: change INF to -INF, min to max
    const int NEUTRAL = INF;

    SegTree(int _n) {
        n = _n;
        seg.assign(4 * n + 5, NEUTRAL);
        lazy.assign(4 * n + 5, 0);
    }

    void push(int l, int r, int pos) {
        if (lazy[pos] == 0) return;
        seg[pos] += lazy[pos];
        if (l != r) {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    void build(const vector<int>& a, int l, int r, int pos) {
        if (l == r) {
            seg[pos] = a[l - 1];
            return;
        }
        int mid = (l + r) / 2;
        build(a, l, mid, pos * 2);
        build(a, mid + 1, r, pos * 2 + 1);
        // [SWITCH] Change min to max here
        seg[pos] = min(seg[pos * 2], seg[pos * 2 + 1]);
    }

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
        // [SWITCH] Change min to max here
        seg[pos] = min(seg[pos * 2], seg[pos * 2 + 1]);
    }

    int query(int l, int r, int pos, int ql, int qr) {
        push(l, r, pos);
        if (ql > r || qr < l) return NEUTRAL;
        if (ql <= l && qr >= r) return seg[pos];
        int mid = (l + r) / 2;
        // [SWITCH] Change min to max here
        return min(query(l, mid, pos * 2, ql, qr), query(mid + 1, r, pos * 2 + 1, ql, qr));
    }

    void build(const vector<int>& a) { build(a, 1, n, 1); }
    void update(int ql, int qr, int val) { update(1, n, 1, ql, qr, val); }
    int query(int ql, int qr) { return query(1, n, 1, ql, qr); }
};

/* Segment Tree for gcd query */
struct SegTree {
    int n;
    vector<int> seg;

    SegTree(int _n) {
        n = _n;
        seg.assign(4 * n + 5, 0);
    }

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    void build(const vector<int>& a, int l, int r, int pos) {
        if (l == r) {
            seg[pos] = a[l - 1];
            return;
        }
        int mid = (l + r) / 2;
        build(a, l, mid, pos * 2);
        build(a, mid + 1, r, pos * 2 + 1);
        seg[pos] = gcd(seg[pos * 2], seg[pos * 2 + 1]);
    }

    void update(int l, int r, int pos, int idx, int val) {
        if (l == r) {
            seg[pos] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(l, mid, pos * 2, idx, val);
        else update(mid + 1, r, pos * 2 + 1, idx, val);
        seg[pos] = gcd(seg[pos * 2], seg[pos * 2 + 1]);
    }

    int query(int l, int r, int pos, int ql, int qr) {
        if (ql > r || qr < l) return 0; // 0 is identity for GCD
        if (ql <= l && qr >= r) return seg[pos];
        int mid = (l + r) / 2;
        return gcd(query(l, mid, pos * 2, ql, qr), query(mid + 1, r, pos * 2 + 1, ql, qr));
    }

    void build(const vector<int>& a) { build(a, 1, n, 1); }
    void update(int idx, int val) { update(1, n, 1, idx, val); }
    int query(int ql, int qr) { return query(1, n, 1, ql, qr); }
};

/* Segment Tree for Frequency query */
struct Node {
    int val;
    int cnt;
};

struct SegTree {
    int n;
    vector<Node> seg;
    vector<int> lazy;
    const int INF_VAL = 1e18;

    SegTree(int _n) {
        n = _n;
        seg.resize(4 * n + 5);
        lazy.assign(4 * n + 5, 0);
    }

    Node merge(Node a, Node b) {
        if (a.val < b.val) return a;
        if (b.val < a.val) return b;
        return {a.val, a.cnt + b.cnt};
    }

    void push(int l, int r, int pos) {
        if (lazy[pos] == 0) return;
        seg[pos].val += lazy[pos];
        if (l != r) {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    void build(const vector<int>& a, int l, int r, int pos) {
        if (l == r) {
            seg[pos] = {a[l - 1], 1};
            return;
        }
        int mid = (l + r) / 2;
        build(a, l, mid, pos * 2);
        build(a, mid + 1, r, pos * 2 + 1);
        seg[pos] = merge(seg[pos * 2], seg[pos * 2 + 1]);
    }

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
        seg[pos] = merge(seg[pos * 2], seg[pos * 2 + 1]);
    }

    Node query(int l, int r, int pos, int ql, int qr) {
        push(l, r, pos);
        if (ql > r || qr < l) return {INF_VAL, 0};
        if (ql <= l && qr >= r) return seg[pos];
        int mid = (l + r) / 2;
        return merge(query(l, mid, pos * 2, ql, qr), query(mid + 1, r, pos * 2 + 1, ql, qr));
    }

    void build(const vector<int>& a) { build(a, 1, n, 1); }
    void update(int ql, int qr, int val) { update(1, n, 1, ql, qr, val); }
    Node query(int ql, int qr) { return query(1, n, 1, ql, qr); }
};

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