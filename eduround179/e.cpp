#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// DSU (Disjoint Set Union) for mapping transformations
struct DSU {
    vector<int> parent;

    DSU() : parent(3) {
        for (int i = 0; i < 3; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Update x's representative to point to the lex smaller of x and y
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        // Always point the higher character to the lower
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        DSU dsu;

        vector<pair<char, char>> ops(q);
        for (int i = 0; i < q; ++i) {
            char x, y;
            cin >> x >> y;
            ops[i] = {x, y};
        }

        // Apply operations in order
        for (auto &[x, y] : ops) {
            int a = dsu.find(x - 'a');
            int b = dsu.find(y - 'a');
            if (a != b) {
                // Always try to map to the smaller character
                if (b < a)
                    dsu.parent[a] = b;
            }
        }

        // Apply final mapping to the string
        for (char &ch : s) {
            ch = 'a' + dsu.find(ch - 'a');
        }

        cout << s << '\n';
    }

    return 0;
}