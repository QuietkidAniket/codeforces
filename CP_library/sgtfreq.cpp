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