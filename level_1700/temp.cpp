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