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