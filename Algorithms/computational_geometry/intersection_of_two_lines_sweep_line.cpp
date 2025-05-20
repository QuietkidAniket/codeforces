#include <bits/stdc++.h>
using namespace std;

struct data {
    int x, y;
};

// Check if two segments intersect
bool intersect(data a, data b, data c, data d) {
    auto cross = [](data p1, data p2, data p3) {
        return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    };
    return (cross(a, b, c) * cross(a, b, d) < 0) &&
           (cross(c, d, a) * cross(c, d, b) < 0);
}

// Sweep Line Algorithm
bool sweepLine(vector<pair<data, data>>& segments) {
    set<data> active;
    sort(segments.begin(), segments.end(), [](pair<data, data> a, pair<data, data> b) {
        return min(a.first.x, a.second.x) < min(b.first.x, b.second.x);
    });

    for (auto& s : segments) {
        auto it = active.lower_bound(s.first);
        if (it != active.end() && intersect(s.first, s.second, *it, *next(it)))
            return true;
        active.insert(s.first);
    }
    return false;
}
