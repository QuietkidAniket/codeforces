struct CompressedOrderedSet {
    map<int, int> val_to_index;
    vector<int> index_to_val;
    vector<int> seg;
    int sz;

    void build(vector<int> vals) {
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        sz = vals.size();
        seg.assign(4 * sz, 0);
        for (int i = 0; i < sz; ++i) {
            val_to_index[vals[i]] = i;
            index_to_val.push_back(vals[i]);
        }
    }

    void update(int idx, int l, int r, int pos, int delta) {
        if (l == r) {
            seg[idx] += delta;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m)
            update(2 * idx, l, m, pos, delta);
        else
            update(2 * idx + 1, m + 1, r, pos, delta);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return seg[idx];
        int m = (l + r) / 2;
        return query(2 * idx, l, m, ql, qr) + query(2 * idx + 1, m + 1, r, ql, qr);
    }

    void insert(int x) {
        update(1, 0, sz - 1, val_to_index[x], 1);
    }

    void erase(int x) {
        update(1, 0, sz - 1, val_to_index[x], -1);
    }

    int order_of_key(int x) {
        auto it = val_to_index.lower_bound(x);
        if (it == val_to_index.begin()) return 0;
        int pos = (--it)->second;
        return query(1, 0, sz - 1, 0, pos);
    }

    int find_by_order(int k) {
        int l = 0, r = sz - 1, ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            int cnt = query(1, 0, sz - 1, 0, m);
            if (cnt > k) {
                r = m - 1;
            } else {
                ans = m;
                l = m + 1;
            }
        }
        return index_to_val[ans];
    }
};