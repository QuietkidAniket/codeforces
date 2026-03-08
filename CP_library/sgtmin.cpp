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