struct OrderedSet {
    int size;
    vector<int> bit;
    OrderedSet(int n = 1e6 + 10) {
        size = n;
        bit.assign(size, 0);
    }

    void insert(int x) {
        for (++x; x < size; x += x & -x) bit[x]++;
    }

    void erase(int x) {
        for (++x; x < size; x += x & -x) bit[x]--;
    }

    int order_of_key(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) res += bit[x];
        return res;
    }

    int find_by_order(int k) {
        int x = 0;
        for (int i = 20; i >= 0; i--) {
            if ((x | (1 << i)) < size && bit[x | (1 << i)] <= k) {
                k -= bit[x | (1 << i)];
                x |= (1 << i);
            }
        }
        return x;
    }
};